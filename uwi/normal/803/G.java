//package educational.round20;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{t, ni()-1, ni()-1, ni()};
			}else{
				qs[i] = new int[]{t, ni()-1, ni()-1};
			}
		}
		int[] xs = new int[2*Q+2];
		int p = 0;
		for(int i = 0;i < Q;i++){
			xs[p++] = qs[i][1];
			xs[p++] = qs[i][2]+1;
		}
		xs[p++] = 0;
		xs[p++] = n*K;
		
		int[] imap = shrinkX(xs);
		int m = imap.length;
		int[] ba = new int[m];
		
		int[][] st = build(a);
		for(int i = 0;i < imap.length-1;i++){
			int l = imap[i], r = imap[i+1];
			if(r-l >= n){
				ba[i] = rmq(st, 0, n);
			}else if(l % n <= r % n){
				ba[i] = rmq(st, l%n, r%n);
			}else{
				ba[i] = Math.min(rmq(st, 0, r%n), rmq(st, l%n, n));
			}
		}
		
		SegmentTreeOverwriteRMQ sto = new SegmentTreeOverwriteRMQ(ba);
		for(int[] q : qs){
			if(q[0] == 1){
				int l = Arrays.binarySearch(imap, q[1]);
				int r = Arrays.binarySearch(imap, q[2]+1);
				sto.update(l, r, q[3]);
			}else{
				int l = Arrays.binarySearch(imap, q[1]);
				int r = Arrays.binarySearch(imap, q[2]+1);
				out.println(sto.min(l, r));
			}
		}
	}
	
	public static class SegmentTreeOverwriteRMQ {
		public int M, H, N;
		public int[] st;
		public int[] cover;
		private int I = Integer.MAX_VALUE;
		
		public SegmentTreeOverwriteRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new int[H];
			Arrays.fill(cover, I);
			st = new int[M];
			Arrays.fill(st, I);
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			if(cover[i] == I){
				st[i] = Math.min(st[2*i], st[2*i+1]);
			}else{
				st[i] = cover[i];
			}
		}
		
		public void update(int l, int r, int v){ update(l, r, v, 0, H, 1); }
		
		private void update(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cr == cl+1){
					st[cur] = v;
				}else{
					cover[cur] = v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				boolean bp = false;
				if(cover[cur] != I){ // back-propagate
					if(2*cur >= H){
						st[2*cur] = st[2*cur+1] = cover[cur];
					}else{
						cover[2*cur] = cover[2*cur+1] = cover[cur];
						bp = true;
					}
					cover[cur] = I;
				}
				if(cl < r && l < mid){
					update(l, r, v, cl, mid, 2*cur);
				}else if(bp){
					propagate(2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, mid, cr, 2*cur+1);
				}else if(bp){
					propagate(2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int min(int l, int r){ return min(l, r, 0, H, 1); }
		
		private int min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				if(cover[cur] != I)return cover[cur];
				int mid = cl+cr>>>1;
				int L = I, R = I;
				if(cl < r && l < mid){
					L = min(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = min(l, r, mid, cr, 2*cur+1);
				}
				return Math.min(L, R);
			}
		}
		
		public int[] toArray() { return toArray(1, 0, H, new int[H]); }
		
		private int[] toArray(int cur, int l, int r, int[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else if(cover[cur] != I){
				Arrays.fill(ret, l, r, cover[cur]);
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
			}
			return ret;
		}
	}

	
	public static int[][] build(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			}else {
				ret[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = Math.min(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}
	
	// [a,b)
	public static int rmq(int[][] or, int a, int b)
	{
		if(a >= b)return Integer.MAX_VALUE;
		// 1:0, 2:1, 3:1, 4:2, 5:2, 6:2, 7:2, 8:3
		int t = 31-Integer.numberOfLeadingZeros(b-a);
		return Math.min(or[t][a], or[t][b-(1<<t)]);
	}

	
	public static int[] shrinkX(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int) (b[0] >> 32);
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0) {
				p++;
				ret[p] = (int) (b[i] >> 32);
			}
			a[(int) b[i]] = p;
		}
		return Arrays.copyOf(ret, p + 1);
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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