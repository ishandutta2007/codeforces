//package round212;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] from = new int[n*n];
		int[] to = new int[n*n];
		int[] w = new int[n*n];
		int q = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int wg = ni();
				if(wg > 0 && i < n-1 && j > 0){
					from[q] = i; to[q] = j; w[q] = wg; q++;
				}
			}
		}
		int[][][] g = packWD(n, from, to, w, q);
		int[][] f = new int[n][n];
		
		// unweighted invgraph
		int[] p = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++)p[g[i][j][0]]++;
		}
		int[][] ig = new int[n][];
		for(int i = 0;i < n;i++)ig[i] = new int[p[i]];
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j < g[i].length;j++){
				ig[g[i][j][0]][--p[g[i][j][0]]] = i;
			}
		}
		
		int F = maximumFlowDinic(g, 0, n-1, f, ig);
		while(K > 0){
			Deque<Integer> qq = new ArrayDeque<Integer>();
			qq.add(0);
			int[] dd = new int[n];
			Arrays.fill(dd, 99999);
			dd[0] = 0;
			int[] prev = new int[n];
			Arrays.fill(prev, -1);
			while(!qq.isEmpty()){
				int cur = qq.poll();
				for(int[] e : g[cur]){
					if(f[cur][e[0]] < e[1]){
						if(dd[e[0]] > dd[cur]){
							dd[e[0]] = dd[cur];
							prev[e[0]] = cur;
							qq.addFirst(e[0]);
						}
					}else if(dd[e[0]] > dd[cur] + 1){
						dd[e[0]] = dd[cur] + 1;
						prev[e[0]] = cur;
						qq.addLast(e[0]);
					}
				}
			}
			
			if(dd[n-1] == 99999 || K < dd[n-1]){
				break;
			}
			
			for(int i = n-1;i != 0;i = prev[i]){
				int pr = prev[i];
				for(int[] e : g[pr]){
					if(e[0] == i && f[pr][e[0]] == e[1]){
						e[1]++;
						K--;
						break;
					}
				}
			}
			
			F += maximumFlowDinic(g, 0, n-1, f, ig);
		}
		out.println(F);
	}
	
	public static int maximumFlowDinic(int[][][] g, int source, int sink, int[][] f, int[][] ig)
	{
		int n = g.length;
		
		int[] d = new int[n];
		int[] q = new int[n];
		int ret = 0;
		while(true){
			Arrays.fill(d, -1);
			q[0] = source;
			int r = 1;
			d[source] = 0;
			
			for(int v = 0;v < r;v++){
				int cur = q[v];
				// plus flow
				for(int[] ne : g[cur]){
					int nex = ne[0], w = ne[1];
					if(d[nex] == -1 && w - f[cur][nex] > 0) {
						q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
				// minus flow
				for(int nex : ig[cur]){
					if(d[nex] == -1 && -f[cur][nex] > 0) {
						q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
			}
			if(d[sink] == -1)break;
			int delta = 0;
			while((delta = dfsDinic(d, g, ig, f, source, sink, Integer.MAX_VALUE)) > 0){
				ret += delta;
			}
		}
		
		return ret;
	}
	
	public static int dfsDinic(int[] d, int[][][] g, int[][] ig, int[][] f, int cur, int t, int min)
	{
		if(cur == t){
			return min;
		}else{
			int left = min;
			for(int[] ne : g[cur]){
				int nex = ne[0], w = ne[1];
				if(d[nex] == d[cur]+1 && w-f[cur][nex] > 0){
					int fl = dfsDinic(d, g, ig, f, nex, t, Math.min(left, w-f[cur][nex]));
					if(fl > 0){
						f[cur][nex] += fl;
						f[nex][cur] -= fl;
						left -= fl;
						if(left == 0)return min;
					}
				}
			}
			for(int nex : ig[cur]){
				if(d[nex] == d[cur]+1 && -f[cur][nex] > 0){
					int fl = dfsDinic(d, g, ig, f, nex, t, Math.min(left, -f[cur][nex]));
					if(fl > 0){
						f[cur][nex] += fl;
						f[nex][cur] -= fl;
						left -= fl;
						if(left == 0)return min;
					}
				}
			}
			return min-left;
		}
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
//		int n = 50, m = 1000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
////				sb.append((i == j ? 0 : gen.nextInt(1000000)) + " ");
//				sb.append((i == j ? 0 : 1000000) + " ");
//			}
//		}
//		INPUT = sb.toString();
		
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