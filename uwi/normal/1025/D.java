//package round505;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		boolean[][][] dp = new boolean[2][n][n];
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				g[i][j] = gcd3(a[i], a[j]) >= 2;
			}
		}
		for(int len = 1;len <= n;len++){
			for(int i = 0;i+len-1 < n;i++){
				int j = i+len-1;
				if(len == 1){
					dp[0][i][j] = i-1 >= 0 && g[i-1][i];
					dp[1][i][j] = i+1 < n && g[i][i+1];
				}else{
					dp[0][i][j] |= i-1 >= 0 && dp[0][i+1][j] && g[i-1][i];
					dp[0][i][j] |= i-1 >= 0 && dp[1][i][j-1] && g[i-1][j];
					dp[1][i][j] |= j+1 < n && dp[1][i][j-1] && g[j][j+1];
					dp[1][i][j] |= j+1 < n && dp[0][i+1][j] && g[i][j+1];
					for(int k = i+1;k <= j-1;k++){
						if(dp[1][i][k-1] && dp[0][k+1][j]){
							dp[0][i][j] |= i-1 >= 0 && g[i-1][k];
							dp[1][i][j] |= j+1 < n && g[k][j+1];
						}
					}
				}
			}
		}
		boolean ans = false;
		ans |= dp[0][1][n-1];
		ans |= dp[1][0][n-2];
		for(int k = 1;k <= n-2;k++){
			ans |= dp[1][0][k-1] && dp[0][k+1][n-1];
		}
		out.println(ans ? "Yes" : "No");
	}
	
	public static long gcd3(long a, long b) {
		if(a == 0)return b;
		if(b == 0)return a;
		
		int ashift = Long.numberOfTrailingZeros(a);
		int bshift = Long.numberOfTrailingZeros(b);
		a >>>= ashift;
		b >>>= bshift;
		while(b != a){
			if(a > b){
				long t = a; a = b; b = t;
			}
			b -= a;
			b >>>= Long.numberOfTrailingZeros(b);
		}
		
		return a<<Math.min(ashift, bshift);
	}

	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void run() throws Exception
	{
//		int n = 700, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int[] a = new int[n];
//		for (int i = 0; i < n; i++) {
//			a[i] = 2*(gen.nextInt(1000000000)+1);
//		}
//		Arrays.sort(a);
//		for(int i = 0;i < n;i++){
//			sb.append(a[i] + " ");
//		}
//		INPUT = sb.toString();

		
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