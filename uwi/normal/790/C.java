//package round405;
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
		int n = ni();
		char[] s = ns(n);
		
		int[][][][] dp = new int[3][n+1][n+1][n+1];
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= n;j++){
				Arrays.fill(dp[0][i][j], 99999999);
				Arrays.fill(dp[1][i][j], 99999999);
				Arrays.fill(dp[2][i][j], 99999999);
			}
		}
		int nv = 0, nk = 0, ne = 0;
		for(char c : s){
			if(c == 'V'){
				nv++;
			}else if(c ==  'K'){
				nk++;
			}else{
				ne++;
			}
		}
		
		// V K ?
		dp[2][0][0][0] = 0;
		int[][][][] poss = new int[3][nv+1][nk+1][ne+1];
		for(int i = 0;i <= nv;i++){
			for(int j = 0;j <= nk;j++){
				for(int k = 0;k <= ne;k++){
					for(int l = 0;l < 3;l++){
						poss[l][i][j][k] = pos(s, i, j, k, l);
					}
				}
			}
		}
		
		for(int i = 0;i <= nv;i++){
			for(int j = 0;j <= nk;j++){
				for(int k = 0;k <= ne;k++){
					if(i+1 <= nv && poss[0][i][j][k] != -1){
						int v = poss[0][i][j][k];
						dp[0][i+1][j][k] = Math.min(dp[0][i+1][j][k], dp[2][i][j][k] + v);
						dp[0][i+1][j][k] = Math.min(dp[0][i+1][j][k], dp[1][i][j][k] + v);
						dp[0][i+1][j][k] = Math.min(dp[0][i+1][j][k], dp[0][i][j][k] + v);
					}
					if(j+1 <= nk && poss[1][i][j][k] != -1){
						int v = poss[1][i][j][k];
						dp[1][i][j+1][k] = Math.min(dp[1][i][j+1][k], dp[2][i][j][k] + v);
						dp[1][i][j+1][k] = Math.min(dp[1][i][j+1][k], dp[1][i][j][k] + v);
					}
					if(k+1 <= ne && poss[2][i][j][k] != -1){
						int v = poss[2][i][j][k];
						dp[2][i][j][k+1] = Math.min(dp[2][i][j][k+1], dp[2][i][j][k] + v);
						dp[2][i][j][k+1] = Math.min(dp[2][i][j][k+1], dp[1][i][j][k] + v);
						dp[2][i][j][k+1] = Math.min(dp[2][i][j][k+1], dp[0][i][j][k] + v);
					}
				}
			}
		}
		out.println(Math.min(Math.min(dp[0][nv][nk][ne], dp[1][nv][nk][ne]), dp[2][nv][nk][ne]));
	}
	
	int pos(char[] s, int a, int b, int c, int k)
	{
		int ret = 0;
		for(char x : s){
			if(x == 'V'){
				if(a == 0){
					if(k == 0)return ret;
					ret++;
				}else{
					a--;
				}
			}else if(x == 'K'){
				if(b == 0){
					if(k == 1)return ret;
					ret++;
				}else{
					b--;
				}
			}else{
				if(c == 0){
					if(k == 2)return ret;
					ret++;
				}else{
					c--;
				}
			}
		}
		return -1;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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