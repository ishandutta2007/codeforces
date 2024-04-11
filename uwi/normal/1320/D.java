//package round625;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[] s = ns(n);
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + s[i]-'0';
		}
		int[] one = new int[n+1];
		for(int i = n-1;i >= 0;i--){
			if(s[i] == '1'){
				one[i] = one[i+1] + 1;
			}else{
				one[i] = 0;
			}
		}
		boolean[] stands = new boolean[n];
		Arrays.fill(stands, true);
		boolean[] first = new boolean[n];
		for(int i = 0;i < n-1;i++){
			if(s[i] == s[i+1] && s[i] == '1'){
				first[i] = true;
				stands[i] = stands[i+1] = false;
				i++;
			}
		}
		
		Random gen = new Random();
		long mul0 = BigInteger.probablePrime(61, gen).longValue();
		SegmentTreeRSQHash st0 = new SegmentTreeRSQHash(s, stands, mul0);
		long mul1 = BigInteger.probablePrime(61, gen).longValue();
		SegmentTreeRSQHash st1 = new SegmentTreeRSQHash(s, stands, mul1);
		
		for(int Q = ni();Q > 0;Q--){
			int a = ni()-1, b = ni()-1, len = ni();
			if(cum[b+len] - cum[b] != cum[a+len] - cum[a]){
				out.println("No");
				continue;
			}
			
			long[] HA0 = hash(a, len, st0, s, stands, first, one);
			long[] HA1 = hash(a, len, st1, s, stands, first, one);
			long[] HB0 = hash(b, len, st0, s, stands, first, one);
			long[] HB1 = hash(b, len, st1, s, stands, first, one);
			if(HA0[0] == HB0[0] && HA0[1] == HB0[1] && HA1[0] == HB1[0]){
				out.println("Yes");
			}else{
				out.println("No");
			}
		}
	}
	
	long[] addLast(long[] h, int x, SegmentTreeRSQHash st)
	{
		return new long[]{
				SegmentTreeRSQHash.mod(SegmentTreeRSQHash.mul(h[0], st.MUL) + x), 
				h[1]+1
				};
	}
	
	long[] addFirst(long[] h, int x, SegmentTreeRSQHash st)
	{
		return new long[]{
				SegmentTreeRSQHash.mod(SegmentTreeRSQHash.mul(st.pows[(int)h[1]], x) + h[0]), 
				h[1]+1
		};
	}
	
	long[] hash(int a, int len, SegmentTreeRSQHash st, char[] s, boolean[] stands, boolean[] first, int[] one)
	{
		if(one[a] >= len){
			if(len % 2 == 1){
				return new long[]{'1', 1};
			}else{
				return new long[]{0, 0};
			}
		}else if(first[a] || stands[a]){
			if(first[a+len-1]){
				return addLast(st.sum(a, a+len), '1', st);
			}else{
				return st.sum(a, a+len);
			}
		}else if(one[a] % 2 == 0){
			if(first[a+len-1]){
				return addLast(st.sum(a+one[a], a+len), '1', st);
			}else{
				return st.sum(a+one[a], a+len);
			}
		}else{
			if(first[a+len-1]){
				return addFirst(addLast(st.sum(a, a+len), '1', st), '1', st);
			}else{
				return addFirst(st.sum(a, a+len), '1', st);
			}
		}
	}
	
	public static class SegmentTreeRSQHash {
		public int M, H, N;
		public long[] st;
		public long MUL;
		public int[] stands;
		
		public long[] pows;
//		public long[] gas;
		
		static long mod = (1L<<61)-1;
		
		public static long mul(long a, long b)
		{
			long al = a&(1L<<31)-1, ah = a>>>31;
			long bl = b&(1L<<31)-1, bh = b>>>31;
			long low = al * bl; // <2^62
			long mid = al * bh + bl * ah; // < 2^62
			long high = ah * bh + (mid>>>31); // < 2^60 + 2^31 < 2^61
			// high*2^62 = high*2 (mod 2^61-1)
			long ret = mod(mod(2*high + low) + ((mid&(1L<<31)-1)<<31));
			return ret;
		}
		
		public static long mod(long a)
		{
			while(a >= mod)a -= mod;
			while(a < 0)a += mod;
			return a;
		}
		
		private static long[] makePows(long M, int n)
		{
			long[] ret = new long[n+1];
			ret[0] = 1;
			for(int i = 1;i <= n;i++)ret[i] = mul(ret[i-1], M);
			return ret;
		}

		
		private void init()
		{
			pows = makePows(MUL, H+1);
		}
		
		public SegmentTreeRSQHash(char[] a, boolean[] stands, long MUL)
		{
			this.MUL = MUL;
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			this.stands = new int[M];
			for(int i = 0;i < N;i++){
				this.stands[H+i] = stands[i] ? 1 : 0;
				st[H+i] = stands[i] ? a[i] : 0;
			}
			init();
			
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			stands[i] = stands[2*i] + stands[2*i+1];
			st[i] = mod(mul(st[2*i], pows[stands[2*i+1]])+st[2*i+1]);
		}
		
		public long[] sum(int l, int r) { 
			return sum(l, r, 0, H, 1);
		}
		
		protected long[] sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return new long[]{st[cur], stands[cur]};
			}else{
				long[] L = null, R = null;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				if(L == null)return R;
				if(R == null)return L;
//				trq(L, R);
				L[0] = mod(mul(L[0], pows[(int)R[1]]) + R[0]);
				L[1] += R[1];
//				trq(L);
				return L;
			}
		}
		private static void trq(Object... o) { System.out.println(Arrays.deepToString(o)); }
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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