//package round418;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int mod = 1000000007;
		int n = ni();
		int[] ds = na(n);
		
		long[][] C = new long[50 + 1][50 + 1];
		for (int i = 0; i <= 50; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
				if (C[i][j] >= mod)
					C[i][j] -= mod;
			}
		}
		
		long[] ip2 = new long[50];
		long i2 = invl(2, mod);
		ip2[0] = 1;
		for(int i = 1;i < 50;i++)ip2[i] = ip2[i-1] * i2 % mod;
		
		// [1][2][]
		long[][][] dp = new long[30][30][30];
		dp[0][0][ds[0]] = ds[0] == 3 ? invl(6, mod) : invl(2, mod);
		for(int i = 1;i < n;i++){
			long[][][] ndp = new long[30][30][30];
			for(int k = 0;k < 30;k++){
				for(int l = 0;k+l < 30;l++){
					for(int m = 1;k+l+m < 30;m++){
						if(dp[k][l][m] == 0)continue;
						// 1
						// 1,2
						for(int c1 = 0;c1 <= k && c1 <= ds[i]-1;c1++){
							for(int c2 = 0;c2 <= l && c1+c2 <= ds[i]-1;c2++){
								int n1 = k-c1+c2, n2 = l-c2;
								int pl = ds[i] - 1 - c1 - c2;
								if(pl == 1)n1++;
								if(pl == 2)n2++;
								long v = m * dp[k][l][m] % mod * C[k][c1] % mod * C[l][c2];
//								tr(i, k, l, m, c1, c2, n1, n2, dp[k][l][m], v);
								if(m-1 > 0){
									ndp[n1][n2][m-1] += v;
									ndp[n1][n2][m-1] %= mod;
								}else if(n1+2*n2+i+1 <= n){
									// 
									ndp[0][0][n1+2*n2] += v % mod * ip2[n2];
									ndp[0][0][n1+2*n2] %= mod;
								}
							}
						}
					}
				}
			}
			dp = ndp;
		}
		out.println(dp[0][0][0]);
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	void run() throws Exception
	{
//		int n = 50, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(2)+2 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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