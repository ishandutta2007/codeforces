//package round275;
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
		int[] par = new int[n];
		par[0] = -1;
		for(int i = 1;i < n;i++){
			par[i] = ni()-1;
		}
		int[][] g = parentToG(par);
		int[][] pars = parents3(g, 0);
		int[] ord = pars[1];
		for(int i = 0;i < n;i++){
			Arrays.sort(g[i]);
		}
		int mod = 1000000007;
		long[][] dp = new long[n][2];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			long[] lr = new long[2];
			lr[0] = 1;
			for(int j = 0;j < g[cur].length;j++){
				int e = g[cur][j];
				if(par[cur] != e){
					long n0 = (lr[0] * dp[e][0] + lr[1] * dp[e][1]) % mod;
					long n1 = (lr[0] * dp[e][1] + lr[1] * dp[e][0]) % mod;
					lr[0] = n0; lr[1] = n1;
				}
			}
			long[] rl = new long[2];
			rl[0] = 1;
			for(int j = g[cur].length-1;j >= 0;j--){
				int e = g[cur][j];
				if(par[cur] != e){
					long n0 = (rl[0] * dp[e][0] + rl[1] * dp[e][1]) % mod;
					long n1 = (rl[0] * dp[e][1] + rl[1] * dp[e][0]) % mod;
					rl[0] = n0; rl[1] = n1;
				}
			}
			long alle = 1;
			for(int j = 0;j < g[cur].length;j++){
				int e = g[cur][j];
				if(par[cur] != e){
					alle = alle * dp[e][0] % mod;
				}
			}
			long[] o = new long[2];
			o[0] = 1;
			for(int j = 0;j < g[cur].length;j++){
				int e = g[cur][j];
				if(par[cur] != e){
					long n0 = (o[0] * 1 + o[1] * dp[e][1]) % mod;
					long n1 = (o[0] * dp[e][1] + o[1] * 1) % mod;
					o[0] = n0; o[1] = n1;
				}
			}
			
//			tr("cur", cur);
//			tr(lr);
//			tr(rl);
//			tr(alle);
			dp[cur][1] = lr[0] + rl[0] - alle + mod;
			dp[cur][0] = lr[1] + rl[1] - o[1] + mod + 1;
			while(dp[cur][0] >= mod)dp[cur][0] -= mod;
			while(dp[cur][1] >= mod)dp[cur][1] -= mod;
		}
		out.println((dp[0][0] + dp[0][1] + mod - 1) % mod);
	}
	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}
	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
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