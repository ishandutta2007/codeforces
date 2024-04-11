//package round369;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] c = na(n);
		int[][] cost = new int[n][];
		for(int i = 0;i < n;i++){
			cost[i] = na(m);
		}
		long[][][] dp = new long[n+1][m][K+1];
		long I = Long.MAX_VALUE / 10;
		for(int i = 0;i <= n;i++){
			for(int j = 0;j < m;j++){
				Arrays.fill(dp[i][j], I);
			}
		}
		dp[0][0][0] = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(int k = 0;k <= K;k++){
					if(dp[i][j][k] == I)continue;
					if(c[i] == 0){
						for(int l = 0;l < m;l++){
							int nk = j != l || i == 0 ? k+1 : k;
							if(nk <= K){
								dp[i+1][l][nk] = Math.min(dp[i+1][l][nk], dp[i][j][k] + cost[i][l]);
							}
						}
					}else{
						{
							int l = c[i]-1;
							int nk = j != l || i == 0 ? k+1 : k;
							if(nk <= K){
								dp[i+1][l][nk] = Math.min(dp[i+1][l][nk], dp[i][j][k]);
							}
						}
					}
				}
			}
		}
		long min = I;
		for(int j = 0;j < m;j++){
			min = Math.min(min, dp[n][j][K]);
		}
		out.println(min == I ? -1 : min);
	}
	
	void run() throws Exception
	{
//		int n = 100, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(0 + " ");
//		}
//		for (int i = 0; i < n*n; i++) {
//			sb.append(gen.nextInt(1000000000)+1 + " ");
//		}
//		INPUT = sb.toString();

		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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