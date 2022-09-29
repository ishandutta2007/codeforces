//package round596;
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
		for(int i = 1;i < n;i++){
			par[i] = ni();
		}
		par[0] = -1;
		
		int[][] g = parentToG(par);
		int[][] pars = parents3(g, 0);
		int[] ord = pars[1];
		
		int[] hs = new int[n];
		long[] F = new long[n];
		int[] args = new int[n];
		Arrays.fill(args, -1);
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			long fh = 0;
			long min = 0;
			for(int e : g[cur]){
				if(par[cur] == e)continue;
				hs[cur] = Math.max(hs[cur], hs[e]+1);
				fh += F[e] + hs[e] + 1;
				long v = F[e] - (F[e] + hs[e] + 1);
				if(v < min){
					min = v;
					args[cur] = e;
				}
			}
			F[cur] = fh + min;
		}
		
		bb = new int[n];
		ops = new int[(int)F[0]];
		dfs(0, -1, g, args, hs);
		assert bp == n;
		assert op == F[0];
		for(int v : bb){
			out.print(v + " ");
		}
		out.println();
		out.println(op);
		for(int v : ops){
			out.print(v + " ");
		}
		out.println();
	}
	
	int[] bb;
	int bp = 0;
	int[] ops;
	int op = 0;
	
	void dfs(int cur, int par, int[][] g, int[] args, int[] hs)
	{
		bb[bp++] = cur;
		int myh = 0;
		for(int e : g[cur]){
			if(e == par)continue;
			if(e == args[cur])continue;
			for(int i = 0;i < myh;i++){
				ops[op++] = e;
			}
			dfs(e, cur, g, args, hs);
			myh = hs[e] + 1;
		}
		if(args[cur] != -1){
			for(int i = 0;i < myh;i++){
				ops[op++] = args[cur];
			}
			dfs(args[cur], cur, g, args, hs);
		}
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