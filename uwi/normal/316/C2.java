//package abbyy3;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] map = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				map[i][j] = ni();
			}
		}
		
		int E = n*(m-1)+m*(n-1)+n*m;
		int[] from = new int[E];
		int[] to = new int[E];
		int[] cost = new int[E];
		int p = 0;
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(i % 2 == j % 2){
					for(int k = 0;k < 4;k++){
						int ni = i + dr[k], nj = j + dc[k];
						if(ni >= 0 && ni < n && nj >= 0 && nj < m){
							from[p] = i*m+j; to[p] = ni*m+nj; cost[p] = map[i][j] == map[ni][nj] ? 0 : 1; p++;
						}
					}
					from[p] = n*m;to[p] = i*m+j; cost[p] = 0; p++;
				}else{
					from[p] = i*m+j;to[p] = n*m+1; cost[p] = 0; p++;
				}
			}
		}
		
		int[][][] g = packWD(n*m+2, from, to, cost, p);
		out.println(solveMinCostFlowCap1(g, n*m, n*m+1, n*m/2));
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
	
	public static int solveMinCostFlowCap1(int[][][] cost, int src, int sink, int all)
	{
		int n = cost.length;
		
		int[][][] flow = new int[n][][];
		for(int i = 0;i < n;i++) {
			flow[i] = new int[cost[i].length][2];
			for(int j = 0;j < cost[i].length;j++){
				flow[i][j][0] = cost[i][j][0];
			}
		}
		
		// unweighted invgraph
		// curi=nextcurnext
		int[][][] ig = new int[n][][];
		{
			int[] p = new int[n];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < cost[i].length;j++)p[cost[i][j][0]]++;
			}
			for(int i = 0;i < n;i++)ig[i] = new int[p[i]][2];
			for(int i = n-1;i >= 0;i--){
				for(int j = 0;j < cost[i].length;j++){
					int u = --p[cost[i][j][0]];
					ig[cost[i][j][0]][u][0] = i;
					ig[cost[i][j][0]][u][1] = j;
				}
			}
		}
		
		int mincost = 0;
		int[] pot = new int[n]; // 
		
		final int[] d = new int[n];
		DQ q = new DQ(Integer.highestOneBit((n+1)*2));
//		Deque<Integer> q = new ArrayDeque<Integer>();
//		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>(){
//			public int compare(Integer a, Integer b)
//			{
//				if(d[a] - d[b] != 0)return d[a] - d[b];
//				return a - b;
//			}
//		});
		
		int[] prev = new int[n];
		while(all > 0){
			// src~sink
			int[] myind = new int[n];
			Arrays.fill(prev, -1);
			Arrays.fill(d, Integer.MAX_VALUE / 2);
			d[src] = 0;
			q.clear();
			q.addLast(src);
			while(!q.isEmpty()){
				int cur = q.pollFirst();
//				if(cur == sink)break;
				for(int i = 0;i < cost[cur].length;i++) {
					int next = cost[cur][i][0];
					if(1 - flow[cur][i][1] > 0){
						int nd = d[cur] + cost[cur][i][1] + pot[cur] - pot[next];
						if(d[next] > nd){
							d[next] = nd;
							prev[next] = cur;
							myind[next] = i;
							if(nd > d[cur]){
								q.addLast(next);
							}else{
								q.addFirst(next);
							}
						}
					}
				}
				for(int i = 0;i < ig[cur].length;i++) {
					int next = ig[cur][i][0];
					int cind = ig[cur][i][1];
					if(flow[next][cind][1] > 0){
						int nd = d[cur] - cost[next][cind][1] + pot[cur] - pot[next];
						if(d[next] > nd){
							d[next] = nd;
							prev[next] = cur;
							myind[next] = -cind-1;
							if(nd > d[cur]){
								q.addLast(next);
							}else{
								q.addFirst(next);
							}
						}
					}
				}
			}
			
			if(prev[sink] == -1)break;
			
			int sumcost = 0;
			for(int i = sink;i != src;i = prev[i]){
				if(myind[i] >= 0){
					sumcost += cost[prev[i]][myind[i]][1];
				}else{
					// cur->next
					// prev[i]->i
					// i
					// ig[cur][j][0]=nextg[next][ig[cur][j][1]] = cur
					int ind = -myind[i]-1;
//					tr(prev[i], ind);
					sumcost -= cost[i][ind][1];
				}
			}
			
			mincost += sumcost;
			for(int i = sink;i != src;i = prev[i]){
				if(myind[i] >= 0){
					flow[prev[i]][myind[i]][1] += 1;
				}else{
					int ind = -myind[i]-1;
					flow[i][ind][1] -= 1;
				}
			}
//			tr(flow);
			
			all -= 1;
			for(int i = 0;i < n;i++){
				pot[i] += d[i];
			}
		}
		return mincost;
	}
	
	public static class DQ {
		public int[] q;
		public int n;
		protected int pt, ph;
		
		public DQ(int n){ this.n = n; q = new int[n]; pt = ph = 0; }
		
		public void addLast(int x){ q[ph] = x; ph = (ph+1)&n-1; }
		public void addFirst(int x){ pt = (pt+n-1)&n-1; q[pt] = x; }
		public int pollFirst(){ int ret = q[pt]; pt = (pt+1)&n-1; return ret; }
		public int pollLast(){ ph = (ph+n-1)&n-1; int ret = q[ph]; return ret; }
		public int getFirst(){ return q[pt]; }
		public int getFirst(int k){ return q[(pt+k)&n-1]; }
		public int getLast(){ return q[(ph+n-1)&n-1]; }
		public int getLast(int k){ return q[(ph+n-k-1)&n-1]; }
		public void clear(){ pt = ph = 0; }
		public int size(){ return (ph-pt+n)&n-1; }
		public boolean isEmpty(){ return ph==pt; }
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
	
	public static void main(String[] args) throws Exception { new C3().run(); }
	
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