//package round323;
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
	char[] s;
	int pos, len;
	int gen = 0;
	char[] nodes;
	int[] par;
	char[] ops;
	
	void solve()
	{
		nodes = new char[500];
		ops = new char[500];
		par = new int[500];
		s = ns().toCharArray();
		pos = 0; len = s.length;
		expr();
		if(pos != len)throw new RuntimeException();
		int n = gen;
		nodes = Arrays.copyOf(nodes, n);
		ops = Arrays.copyOf(ops, n);
		par = Arrays.copyOf(par, n);
		
		par[0] = -1;
		int[][] g = parentToG(par);
		int[][] pars = parents3(g, 0);
		
		int m = ni();
		int[][] fs = new int[m][];
		for(int i = 0;i < m;i++){
			fs[i] = na(5);
		}
		
		int mod = 1000000007;
		int[] ord = pars[1];
		long[][] dp = new long[n][1<<m];
		long[] ldp = new long[1<<m];
		long[][] T = new long[2][1<<m];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			if(nodes[cur] != 0){
				for(char c = 'A';c <= 'D';c++){
					if(nodes[cur] == c || nodes[cur] == '?'){
						int q = c-'A';
						int v = 0;
						for(int j = 0;j < m;j++){
							if(fs[j][q] == 1)v |= 1<<j;
						}
						dp[cur][v]++;
					}
				}
				for(char c = 'a';c <= 'd';c++){
					if(nodes[cur] == c || nodes[cur] == '?'){
						int q = c-'a';
						int v = 0;
						for(int j = 0;j < m;j++){
							if(fs[j][q] == 0)v |= 1<<j;
						}
						dp[cur][v]++;
					}
				}
			}else{
				int[] ch = new int[2];
				int q = 0;
				for(int e : g[cur]){
					if(par[cur] != e){
						ch[q++] = e;
					}
				}
				
				if(ops[cur] == '&' || ops[cur] == '?'){
					for(int e = 0;e < 2;e++){
						System.arraycopy(dp[ch[e]], 0, T[e], 0, 1<<m);
						for(int j = 0;j < m;j++){
							for(int k = 0;k < 1<<m;k++){
								if(k<<~j>=0){
									T[e][k] += T[e][k|1<<j];
									if(T[e][k] >= mod)T[e][k] -= mod;
								}
							}
						}
					}
					for(int k = 0;k < 1<<m;k++){
						ldp[k] = T[0][k] * T[1][k] % mod;
					}
					for(int j = 0;j < m;j++){
						for(int k = 0;k < 1<<m;k++){
							if(k<<~j>=0){
								ldp[k] -= ldp[k|1<<j];
								if(ldp[k] < 0)ldp[k] += mod;
							}
						}
					}
					for(int k = 0;k < 1<<m;k++){
						dp[cur][k] += ldp[k];
						if(dp[cur][k] >= mod)dp[cur][k] -= mod;
					}
				}
				if(ops[cur] == '|' || ops[cur] == '?'){
					for(int e = 0;e < 2;e++){
						System.arraycopy(dp[ch[e]], 0, T[e], 0, 1<<m);
						for(int j = 0;j < m;j++){
							for(int k = 0;k < 1<<m;k++){
								if(k<<~j>=0){
									T[e][k|1<<j] += T[e][k];
									if(T[e][k|1<<j] >= mod)T[e][k|1<<j] -= mod;
								}
							}
						}
					}
					for(int k = 0;k < 1<<m;k++){
						ldp[k] = T[0][k] * T[1][k] % mod;
					}
					for(int j = 0;j < m;j++){
						for(int k = 0;k < 1<<m;k++){
							if(k<<~j>=0){
								ldp[k|1<<j] -= ldp[k];
								if(ldp[k|1<<j] < 0)ldp[k|1<<j] += mod;
							}
						}
					}
					for(int k = 0;k < 1<<m;k++){
						dp[cur][k] += ldp[k];
						if(dp[cur][k] >= mod)dp[cur][k] -= mod;
					}
				}
			}
		}
		int ptn = 0;
		for(int i = 0;i < m;i++){
			ptn |= fs[i][4]<<i;
		}
		out.println(dp[0][ptn]);
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

	
	int expr()
	{
		int id = gen++;
		if(s[pos] == '('){
			pos++;
			int L = expr();
			pos++; // )
			ops[id] = s[pos++];
			pos++; // (
			int R = expr();
			pos++; // )
			par[L] = id;
			par[R] = id;
		}else{
			nodes[id] = s[pos++];
		}
		return id;
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