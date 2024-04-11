//package round625;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), P = ni();
		int[] a = new int[n];
		int[] ca = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
			ca[i] = ni();
		}
		
		int[] b = new int[m];
		int[] cb = new int[m];
		for(int i = 0;i < m;i++){
			b[i] = ni();
			cb[i] = ni();
		}
		
		int[][] xs = new int[P][];
		for(int i = 0;i < P;i++){
			int x = ni(), y = ni(), z = ni();
			xs[i] = new int[]{y, x, z};
		}
		int[] ys = new int[n+P];
		for(int i = 0;i < n;i++){
			ys[i] = a[i];
		}
		for(int i = 0;i < P;i++){
			ys[i+n] = xs[i][1];
		}
		ys = shrink(ys);
		for(int i = 0;i < n;i++){
			a[i] = ys[i];
		}
		for(int i = 0;i < P;i++){
			xs[i][1] = ys[i+n];
		}
		
		int[][] es = new int[m+P][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{b[i], cb[i]};
		}
		for(int i = 0;i < P;i++){
			es[i+m] = xs[i];
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a.length - b.length;
			}
		});

		long[] base = new long[n+P];
		Arrays.fill(base, Long.MAX_VALUE / 3);
		for(int i = 0;i < n;i++){
			base[a[i]] = Math.min(base[a[i]], ca[i]);
		}
		StarrySkyTreeL sst = new StarrySkyTreeL(base);
		long prof = Long.MIN_VALUE;
		for(int[] e : es){
			if(e.length == 2){
				long v = -e[1] + -sst.min(0, n+P);
				prof = Math.max(prof, v);
			}else{
				sst.add(e[1]+1, n+P, -e[2]);
			}
		}
		out.println(prof);
	}
	
	public static class StarrySkyTreeL {
		public int M, H, N;
		public long[] st;
		public long[] plus;
		public long I = Long.MAX_VALUE/4; // I+plus<long
		
		public StarrySkyTreeL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			plus = new long[H];
		}
		
		public StarrySkyTreeL(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new long[H];
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
		}
		
		public void add(int l, int r, long v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, long v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}
		
		public void fall(int i)
		{
			if(i < H){
				if(2*i < H){
					plus[2*i] += plus[i];
					plus[2*i+1] += plus[i];
				}
				st[2*i] += plus[i];
				st[2*i+1] += plus[i];
				plus[i] = 0;
			}
		}
		
		public int firstle(int l, long v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
				}
			}
		}
		
		public int lastle(int l, long v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}
		
		public void addx(int l, int r, long v){
			if(l >= r)return;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				if(f == 1){
					st[(H+l)/f] += v;
				}else{
					plus[(H+l)/f] += v;
				}
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				if(f == 1){
					st[(H+r)/f-1] += v;
				}else{
					plus[(H+r)/f-1] += v;
				}
				r -= f;
			}
		}
		
		public long minx(int l, int r){
			long lmin = I;
			if(l >= r)return lmin;
			if(l != 0){
				for(int d = 0;H>>>d > 0;d++){
					if(d > 0){
						int id = (H+l-1>>>d);
						lmin += plus[id];
					}
					if(l<<~d<0 && l+(1<<d) <= r){
						long v = st[H+l>>>d];
						if(v < lmin)lmin = v;
						l += 1<<d;
					}
				}
			}
			long rmin = I;
			for(int d = 0;H>>>d > 0;d++){
				if(d > 0 && r < H)rmin += plus[H+r>>>d];
				if(r<<~d<0 && l < r){
					long v = st[(H+r>>>d)-1];
					if(v < rmin)rmin = v;
					r -= 1<<d;
				}
			}
			long min = Math.min(lmin, rmin);
			return min;
		}
		
		public long[] toArray() { return toArray(1, 0, H, new long[H]); }
		
		private long[] toArray(int cur, int l, int r, long[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
		}
	}

	
	public static int[] shrink(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0)
				p++;
			ret[(int) b[i]] = p;
		}
		return ret;
	}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}