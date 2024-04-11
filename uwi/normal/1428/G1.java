//package raif;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G3 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "999999 1 2 3 4 5 6 1 999999";
	String INPUT = "";

	void solve()
	{
		int K = ni();
		long[] F = nal(6);
		long I = Long.MIN_VALUE / 2;
		for(int Q = ni();Q > 0;Q--){
			int n = ni();
			long[] dp = {0L};
			for(int i = 0;i < 6;i++, n /= 10){
				int dd = n % 10;
				long[] ndp = new long[n/10+1];
				Arrays.fill(ndp, I);
				SegmentTreeRMQL[] st = new SegmentTreeRMQL[3];
				for(int j = 0;j < 3;j++){
					long[] b = new long[dp.length/3+1];
					for(int k = j;k < dp.length;k+=3){
						b[k/3] = -(dp[k] - F[i] * (k/3));
					}
					st[j] = new SegmentTreeRMQL(b);
				}

				for(int c = 0;c < ndp.length;c++){
					int val = c*10 + dd;
					// val-t <= 9k
					for(int rem = 0;rem < 3;rem++) {
						int inf = Math.max(val-9*(K-1), 0);
						int sup = Math.min(dp.length-1, val);
						inf = Math.max(0, (inf+3-rem)/3-1);
						sup = (sup+3-rem)/3-1;
//						tr(inf, sup+1, dp.length/3+1);
						long v = -st[rem].min(inf, sup+1) + (val-rem)/3*F[i];
						ndp[c] = Math.max(ndp[c], v);
					}
					for(int t = Math.max(val-9*K, 0);t <= val-9*(K-1) && t < dp.length;t++){
						int m = val-t;
						int got = m/3;
						if(m % 3 != 0){
							got = 3*(K-1);
						}
						ndp[c] = Math.max(ndp[c], got*F[i] + dp[t]);
					}
				}
				dp = ndp;
			}
			out.println(dp[0]);
		}
	}

	public static class SegmentTreeRMQL {
		public final int M, H, N;
		public long[] vals;
		public static final long I = Long.MAX_VALUE/3;

		public SegmentTreeRMQL(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			vals = new long[M];
			Arrays.fill(vals, 0, M, I);
		}

		public SegmentTreeRMQL(long[] a)
		{
			this(a.length);
			for(int i = 0;i < N;i++){
				vals[H+i] = a[i];
			}
			//		Arrays.fill(vals, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		public void update(int pos, long x)
		{
			vals[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}

		private void propagate(int i)
		{
			vals[i] = Math.min(vals[2*i], vals[2*i+1]);
		}

		public long min(int l, int r){
			long min = I;
			if(l >= r)return min;
			l += H; r += H;
			for(;l < r;l>>>=1,r>>>=1){
				if((l&1) == 1)min = Math.min(min, vals[l++]);
				if((r&1) == 1)min = Math.min(min, vals[--r]);
			}
			return min;
		}

		public int firstle(int l, long v) {
			if(l >= H)return -1;
			int cur = H+l;
			while(true){
				if(vals[cur] <= v){
					if(cur >= H)return cur-H;
					cur = 2*cur;
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					if((cur&1)==0)cur>>>=1;
				}
			}
		}

		public int lastle(int l, long v) {
			if(l < 0)return -1;
			int cur = H+l;
			while(true){
				if(vals[cur] <= v){
					if(cur >= H)return cur-H;
					cur = 2*cur + 1;
				}else{
					if((cur&cur-1) == 0)return -1;
					cur--;
					if((cur&1)==1)cur>>>=1;
				}
			}
		}
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
	
	public static void main(String[] args) throws Exception { new G3().run(); }
	
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

	private long[] nal(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
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