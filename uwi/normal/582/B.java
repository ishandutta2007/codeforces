//package round323;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static int X = -200;
	
	void solve()
	{
		int n = ni(), T = ni();
		int[] a = shrink(na(n));
		
		int Z = 100;
		int[][] M = new int[Z][Z];
		for(int i = 0;i < Z;i++){
			for(int j = 0;j < Z;j++){
				M[i][j] = X;
			}
		}
		for(int i = 0;i < Z;i++){
			int[] dp = new int[Z];
			for(int j = 0;j < i;j++)dp[j] = -99999999;
			
			for(int j = 0;j < n;j++){
				int max = -99999999;
				for(int k = 0;k <= a[j];k++){
					max = Math.max(max, dp[k]);
				}
				dp[a[j]] = max + 1;
			}
			for(int j = i;j < Z;j++){
				M[j][i] = Math.max(0, dp[j]);
			}
		}
		int[] v = new int[Z];
		Arrays.fill(v, -1111111111);
		v[0] = 0;
		v = pow(M, v, T);
		int max = 0;
		for(int w : v)max = Math.max(max, w);
		out.println(max);
	}
	
	public static int[] mul(int[][] A, int[] v)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			int sum = X;
			for(int k = 0;k < n;k++){
				if(A[i][k] >= 0 && v[k] >= 0){
					int x = A[i][k] + v[k];
					if(x > sum)sum = x;
				}
			}
			w[i] = sum;
		}
		return w;
	}
	
	public static int[][] p2(int[][] A)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
//			Arrays.fill(C[i], Integer.MIN_VALUE);
			Arrays.fill(C[i], X);
			for(int k = 0;k < n;k++){
				for(int j = 0;j < n;j++){
					if(A[i][k] >= 0 && A[k][j] >= 0){
						int x = A[i][k] + A[k][j];
						if(x > C[i][j])C[i][j] = x;
					}
				}
			}
		}
		return C;
	}
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long m)
	{
		int[][] mu = A;
		int[] r = v;
		for(;m > 0;m>>>=1){
			if(m<<63<0)r = mul(mu, r);
			mu = p2(mu);
		}
		return r;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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