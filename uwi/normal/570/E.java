//package round316;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		if(n > m){
			map = trans(map);
			int d = n; n = m; m = d;
		}
		int mod = 1000000007;
		long[][] dp = new long[1][1];
		if(map[0][0] != map[n-1][m-1]){
			out.println(0);
			return;
		}
		dp[0][0] = 1;
		int cw = 1;
		int[] dr = { 1, 0};
		int[] dc = { 0, 1};
		int i = 0, j = n-1+m-1;
		for(;i+1 < j;i++,j--){
			int w = i+1 < n ? i+2 : n;
			long[][] ndp = new long[w][w];
			for(int k = 0;k < cw;k++){
				for(int L = 0;L < cw;L++){
					if(dp[k][L] == 0)continue;
					// k, i-k
					// n-1-l, m-1-(j-l)
					for(int u = 0;u < 2;u++){
						for(int v = 0;v < 2;v++){
							int nr = k+dr[u], nc = i-k+dc[u];
							int mr = n-1-L-dr[v], mc = j-(n-1-L)-dc[v];
							if(nr < n && mr >= 0){
								if(map[nr][nc] == map[mr][mc]){
									ndp[nr][n-1-mr] += dp[k][L];
									if(ndp[nr][n-1-mr] >= mod){
										ndp[nr][n-1-mr] -= mod;
									}
								}
							}
						}
					}
				}
			}
			cw = w;
			dp = ndp;
		}
		if(i == j){
			assert cw == n;
			long ret = 0;
			for(int k = 0;k < cw;k++){
				ret += dp[k][cw-1-k];
			}
			out.println(ret%mod);
		}else{
			assert cw == n;
			long ret = 0;
			for(int k = 0;k < cw;k++){
				ret += dp[k][cw-1-k];
			}
			for(int k = 0;k < cw-1;k++){
				ret += dp[k][cw-2-k];
			}
			out.println(ret%mod);
		}
	}
	
	static char[][] trans(char[][] a)
	{
		int n = a.length, m = a[0].length;
		char[][] ret = new char[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				ret[j][i] = a[i][j];
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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