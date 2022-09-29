//package educational.round65;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[] ai(int[] a)
	{
		int n = a.length;
		long[] ai = new long[n];
		for(int i = 0;i < n;i++)ai[i] = (long)a[i]<<32|i;
		Arrays.sort(ai);
		return ai;
	}
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		long[] ai = ai(a);
		
		SegmentTreeRSQ st = new SegmentTreeRSQ(n);
		SegmentTreeRSQ str = new SegmentTreeRSQ(n);
		
		long ans = 0;
		int mod = 1000000007;
		for(long e : ai){
			int pos = (int)e;
			long val = e>>>32;
			long R = st.sum(pos, n);
			long L = str.sum(n-1-pos, n);
			ans += ((pos+1)*R+(n-pos)*L+(long)(pos+1)*(n-pos)) % mod * val;
			ans %= mod;
			st.stand(pos, 1);
			str.stand(n-1-pos, 1);
		}
		out.println(ans);
	}
	
	public static class SegmentTreeRSQ {
		public int M, H, N;
		public long[] sums;
		public long[] stands;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			sums = new long[M+100];
			stands = new long[M+100];
		}
		
		public void stand(int pos, int v)
		{
			stands[H+pos] += v;
			sums[H+pos] += v;
			for(int i = H+pos>>1;i >= 1;i >>>= 1){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			int count = H/Integer.highestOneBit(2*i);
			
			stands[i] = stands[2*i] + stands[2*i+1];
			sums[i] = sums[2*i] + sums[2*i+1] + stands[2*i] * count;
		}
		
		int tgen;
		
		public long sum(int l, int r) { 
			tgen = M;
			return sums[sum(l, r, 0, H, 1)];
		}
		
		private int sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return cur;
			}else{
				int mid = cl+cr>>>1;
				int L = -1, R = -1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				if(L == -1)return R;
				if(R == -1)return L;
				sums[tgen] = sums[L] + sums[R] + stands[L] * (Math.min(r,cr)-Math.max(l,mid));
				stands[tgen] = stands[L] + stands[R];
				return tgen++;
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