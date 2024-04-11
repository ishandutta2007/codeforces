//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Round568G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 
	
	void solve()
	{
		int n = ni(), T = ni();
		int mod = 1000000007;
		int[][] a = new int[3][n];
		int[] ap = new int[3];
		for(int i = 0;i < n;i++){
			int t = ni();
			int k = ni()-1;
			a[k][ap[k]++] = t;
		}
		for(int i = 0;i < 3;i++)a[i] = Arrays.copyOf(a[i], ap[i]);
		
		long[][][][] com = new long[3][ap[0]+2][ap[1]+2][ap[2]+2];
		com[0][1][0][0] = com[1][0][1][0] = com[2][0][0][1] = 1;
		for(int i = 0;i <= ap[0];i++){
			for(int j = 0;j <= ap[1];j++){
				for(int k = 0;k <= ap[2];k++){
					for(int u = 0;u < 3;u++){
						if(u != 0){
							com[0][i+1][j][k] += com[u][i][j][k];
							if(com[0][i+1][j][k] >= mod)com[0][i+1][j][k] -= mod;
						}
						if(u != 1){
							com[1][i][j+1][k] += com[u][i][j][k];
							if(com[1][i][j+1][k] >= mod)com[1][i][j+1][k] -= mod;
						}
						if(u != 2){
							com[2][i][j][k+1] += com[u][i][j][k];
							if(com[2][i][j][k+1] >= mod)com[2][i][j][k+1] -= mod;
						}
					}
				}
			}
		}
		
		int[][] fif = enumFIF(200, mod);
		
		long[][][] dp = new long[3][][];
		for(int i = 0;i < 3;i++){
			int s = 0;
			for(int v : a[i])s += v;
			dp[i] = new long[ap[i]+1][s+1];
			dp[i][0][0] = 1;
			for(int v : a[i]){
				for(int j = ap[i]-1;j >= 0;j--){
					for(int k = s-v;k >= 0;k--){
						dp[i][j+1][k+v] += dp[i][j][k];
						if(dp[i][j+1][k+v] >= mod)dp[i][j+1][k+v] -= mod;
					}
				}
			}
		}
		
		long[][][] con = new long[ap[0]+1][ap[1]+1][2501];
		for(int i = 0;i <= ap[0];i++){
			for(int j = 0;j <= ap[1];j++){
				for(int k = 0;k < dp[0][i].length;k++){
					if(dp[0][i][k] == 0)continue;
					for(int l = 0;l < dp[1][j].length;l++){
						con[i][j][k+l] += dp[0][i][k] * dp[1][j][l];
						con[i][j][k+l] %= mod;
					}
				}
			}
		}
		
		long ans = 0;
		for(int i = 0;i <= ap[0];i++){
			for(int j = 0;j <= ap[1];j++){
				for(int k = 0;k <= ap[2];k++){
					long base = (com[0][i][j][k] + com[1][i][j][k] + com[2][i][j][k]) * fif[0][i] % mod * fif[0][j] % mod * 
							fif[0][k] % mod;
					long ls = 0;
					for(int l = 0;l <= T;l++){
						if(T-l < dp[2][k].length){
							ls += con[i][j][l] * dp[2][k][T-l];
							ls %= mod;
						}
					}
//					if(base > 0 && ls > 0){
//						tr(i, j, k, base, ls);
//					}
					ans += base * ls;
					ans %= mod;
				}
			}
		}
		out.println(ans);
	}
	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
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
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
	}

	
	void run() throws Exception
	{
//		int n = 50, m = 2500;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(50 + " ");
//			sb.append(gen.nextInt(3)+1 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new Round568G().run(); }
	
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