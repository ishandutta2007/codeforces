//package round360;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		int[][] ig = packD(n, to, from);
		int[] clus = decomposeToSCCNoRec(g, ig);
		int[][] cg = collect(g, clus);
		int u = cg.length;
		int[] cf = new int[u];
		for(int i = 0;i < n;i++)cf[clus[i]]++;
		long ret = 0;
		for(int i = 0;i < cg.length;i++){
			if(cg[i].length == 0){
				if(cf[i] == 1){
					ret++;
				}else{
					int pe = 999999;
					for(int j = 0;j < n;j++){
						if(clus[j] == i){
							pe = Math.min(pe, go(j, clus, g));
						}
					}
					assert pe < 999999;
					assert pe > 1;
					ret += cf[i]-pe + 1000 + 999*(pe-1);
				}
			}else{
				ret += cf[i];
			}
		}
		out.println(ret);
	}
	
	int go(int start, int[] clus, int[][] g)
	{
		int c = clus[start];
		int n = g.length;
		int[] d = new int[n];
		int I = 999999;
		Arrays.fill(d, I);
		d[start] = 0;
		int[] q = new int[n];
		int p = 0;
		q[p++] = start;
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int e : g[cur]){
				if(clus[e] != c)continue;
				if(e == start){
					return d[cur] + 1;
				}
				if(d[e] == I){
					d[e] = d[cur] + 1;
					q[p++] = e;
				}
			}
		}
		return I;
	}
	
	public static int[] decomposeToSCCNoRec(int[][] g, int[][] ig)
	{
		int n = g.length;
		boolean[] visited = new boolean[n];
		int[] po = new int[n];
		int pop = 0;
		
		int[] stack = new int[n];
		int[] sinds = new int[n];
		int sp = 0;
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				sinds[sp] = 0;
				stack[sp++] = i;
				while(sp > 0){
					int cur = stack[sp-1];
					visited[cur] = true;
					while(sinds[sp-1] < g[cur].length && visited[g[cur][sinds[sp-1]]])sinds[sp-1]++;
					if(sinds[sp-1] == g[cur].length){
						po[pop++] = cur;
						sp--;
					}else{
						stack[sp] = g[cur][sinds[sp-1]];
						sinds[sp] = 0;
						sp++;
					}
				}
			}
		}
		
		int[] ret = new int[n];
		Arrays.fill(visited, false);
		int clus = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = n - 1;i >= 0;i--){
			if(!visited[po[i]]){
				q.add(po[i]);
				visited[po[i]] = true;
				while(!q.isEmpty()){
					int cur = q.poll();
					ret[cur] = clus;
					for(int k : ig[cur]){
						if(!visited[k]){
							q.add(k);
							visited[k] = true;
						}
					}
				}
				clus++;
			}
		}
		
		return ret;
	}
	
	public static int[][] collect(int[][] g, int[] clus)
	{
		int n = g.length;
		int m = 0;
		for(int i = 0;i < n;i++)m = Math.max(m, clus[i]);
		m++;
		
		int[] cp = new int[m];
		for(int i = 0;i < n;i++){
			cp[clus[i]] += g[i].length;
		}
		int[][] c = new int[m][];
		for(int i = 0;i < m;i++){
			c[i] = new int[cp[i]];
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				c[clus[i]][--cp[clus[i]]] = clus[g[i][j]];
			}
		}
		
		for(int i = 0;i < m;i++){
			Arrays.sort(c[i]);
			int jp = 0;
			for(int j = 0;j < c[i].length;j++){
				if((j == 0 || c[i][j] != c[i][j-1]) && c[i][j] != i){
					c[i][jp++] = c[i][j];
				}
			}
			c[i] = Arrays.copyOf(c[i], jp);
		}
		return c;
	}

	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
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