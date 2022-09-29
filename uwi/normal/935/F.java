//package round465;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	LST peak;
	LST valley;
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		long[] b = new long[n-1];
		for(int i = 0;i < n-1;i++){
			b[i] = Math.abs(a[i] - a[i+1]);
		}
		peak = new LST(n+3);
		valley = new LST(n+3);
		for(int i = 1;i < n-1;i++){
			if(a[i-1] <= a[i] && a[i] >= a[i+1]){
				peak.set(i);
			}
			if(a[i-1] >= a[i] && a[i] <= a[i+1]){
				valley.set(i);
			}
		}
		// 6 5 6
		// 1 -1
		// x-1+x-1
		// D >= 0 -> x
		// x + 2*D
		// -D
		
		
		// max(0, x-2a)+max(0, x-2b)
		// x>=max(a,b) 2x-a-b
		// x in [a,b] x-a
		// else 0
		long[] fta = new long[n+3];
		for(int i = 0;i < n;i++){
			addFenwick(fta, i, a[i]);
			addFenwick(fta, i+1, -a[i]);
		}
		long[] ftb = buildFenwick(b);
		SegmentTreeRMQL stb = new SegmentTreeRMQL(b);
		
		for(int Q = ni();Q > 0;Q--){
			int t = ni();
			if(t == 1){
				int l = ni()-1, r = ni()-1;
				long x = ni();
				// [l,r-1]
				int ne = peak.next(l);
//				tr(ne, r, sumFenwick(ftb, n-1));
				if(ne != -1 && ne <= r){
					out.println(sumFenwick(ftb, n-2) + 2L*x);
				}else{
					// no peak
					// one or no valley
					int val = valley.next(l);
					long max = -2L*x;
					if(val != -1 && val <= r){
						if(l < r){
							long u = Math.min(stb.minx(l-1, val-1), stb.minx(val+1, r+1));
							max = Math.max(max, (x >= u ? x-2*u : -x) + x);
						}
						max = Math.max(max, 
								(x >= b[val-1] ? x-2*b[val-1] : -x) + 
								(x >= b[val] ? x-2*b[val] : -x)
								);
					}else{
						if(sumFenwick(fta, l-1) <= sumFenwick(fta, r+1)){
							r = Math.min(r+1, n-1);
							if(l < r){
								long u = stb.minx(l, r);
								max = Math.max(max, (x >= u ? x-2*u : -x) + x);
							}
						}else{
							l = Math.max(l-1, 0);
							if(l < r){
								long u = stb.minx(l, r);
								max = Math.max(max, (x >= u ? x-2*u : -x) + x);
							}
						}
					}
					out.println(sumFenwick(ftb, n-2) + max);
				}
			}else{
				int l = ni()-1, r = ni()-1, v = ni();
				addFenwick(fta, l, v);
				addFenwick(fta, r+1, -v);
				if(l >= 1){
					long nv = Math.abs(sumFenwick(fta, l)-sumFenwick(fta, l-1));
					addFenwick(ftb, l-1, nv - b[l-1]);
					stb.update(l-1, nv);
					b[l-1] = nv;
				}
				if(r < n-1){
					long nv = Math.abs(sumFenwick(fta, r)-sumFenwick(fta, r+1));
					addFenwick(ftb, r, nv - b[r]);
					stb.update(r, nv);
					b[r] = nv;
				}
				update(l-1, fta, n);
				update(l, fta, n);
				update(r, fta, n);
				update(r+1, fta, n);
			}
//			tr(peak, valley);
//			tr("a", restoreFenwick(fta));
//			tr("b", restoreFenwick(ftb));
		}
	}
	
	public static class SegmentTreeRMQL {
		public int M, H, N;
		public long[] st;
		
		public SegmentTreeRMQL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			Arrays.fill(st, 0, M, Long.MAX_VALUE/3);
		}
		
		public SegmentTreeRMQL(long[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			Arrays.fill(st, H+N, M, Long.MAX_VALUE/3);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, long x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public long minx(int l, int r){
			long min = Long.MAX_VALUE/3;
			if(l >= r)return min;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				long v = st[(H+l)/f];
				if(v < min)min = v;
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				long v = st[(H+r)/f-1];
				if(v < min)min = v;
				r -= f;
			}
			return min;
		}
		
		public long min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}
		
		private long min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				long ret = Long.MAX_VALUE/3;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret;
			}
		}
		
		public int firstle(int l, long v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					if((cur&1)==0)cur>>>=1;
				}
			}
		}
		
		public int lastle(int l, long v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur--;
					if((cur&1)==1)cur>>>=1;
				}
			}
		}
	}

	
	void update(int x, long[] ft, int n)
	{
		if(x <= 0 || x >= n-1)return;
		if(sumFenwick(ft, x-1) <= sumFenwick(ft, x) &&
				sumFenwick(ft, x) >= sumFenwick(ft, x+1)){
			peak.set(x);
		}else{
			peak.unset(x);
		}
		if(sumFenwick(ft, x-1) >= sumFenwick(ft, x) &&
				sumFenwick(ft, x) <= sumFenwick(ft, x+1)){
			valley.set(x);
		}else{
			valley.unset(x);
		}
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}

	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//			size = 0;
		}
		
		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = set<<~n;
			if(h == 0L)return -1;
			return -Long.numberOfLeadingZeros(h)+n;
		}
		
		private static int next(long set, int n)
		{
			long h = set>>>n;
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
	}

	
	public static long[] buildFenwick(long[] a)
	{
		int n = a.length;
		long[] ft = new long[n+5];
		System.arraycopy(a, 0, ft, 1, n);
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}

	public static long[] buildFenwick(int[] a)
	{
		int n = a.length;
		long[] ft = new long[n+5];
		for(int i = 0;i < n;i++){
			ft[i+1] = a[i];
		}
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}

	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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