//package round523;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[][] go(int[][] g, int root)
	{
		int n = g.length;
		int q = ni();
		int[] cons = new int[n];
		Arrays.fill(cons, -99999999);
		for(int i = 0;i < q;i++){
			int K = ni()-1;
			int X = ni();
			if(cons[K] != -99999999 && cons[K] != X)return null;
			cons[K] = X;
		}
		int[] clus = new int[n];
		dfs(root, -1, g, cons, root, clus);
		for(int i = 0;i < n;i++){
			if(cons[i] > -99999999 && cons[i] < 0)return null;
		}
		return new int[][]{clus, cons};
	}
	
	int dfs(int cur, int pre, int[][] g, int[] cons, int root, int[] clus)
	{
		if(cons[cur] >= 0){
			root = cur;
		}
		clus[cur] = root;
		int cs = 0;
		for(int e : g[cur]){
			if(e == pre)continue;
			int csum = dfs(e, cur, g, cons, root, clus);
			cs += csum;
		}
		if(cons[cur] >= 0){
			int ret = cons[cur];
			cons[cur] -= cs;
			return ret;
		}else{
			return cs;
		}
	}
	
	void solve()
	{
		int n = ni(), x = ni()-1, y = ni()-1;
		int[] a = na(n);
		int[][] gx = nt(n);
		int[][] gy = nt(n);
		
		int[][] ccx = go(gx, x);
		int[][] ccy = go(gy, y);
		if(ccx == null || ccy == null){
			out.println(-1);
			return;
		}
		int csumx = 0;
		int csumy = 0;
		for(int i = 0;i < n;i++){
			if(ccx[1][i] >= 0)csumx += ccx[1][i];
			if(ccy[1][i] >= 0)csumy += ccy[1][i];
		}
		if(csumx != csumy){
			out.println(-1);
			return;
		}
		
		List<Edge> es = new ArrayList<>();
		int src = 4*n, sink = src + 1;
		for(int i = 0;i < n;i++){
			if(ccx[1][i] >= 0)es.add(new Edge(src, i, ccx[1][i], 0));
			es.add(new Edge(ccx[0][i], n+i, 1, 0));
			es.add(new Edge(n+i, 2*n+i, 1, 100000-a[i]));
			es.add(new Edge(2*n+i, 3*n+ccy[0][i], 1, 0));
			if(ccy[1][i] >= 0)es.add(new Edge(3*n+i, sink, ccy[1][i], 0));
		}
		
		long C = solveMinCostFlowWithSPFA(compileWD(sink+1, es), src, sink, csumx);
		if(C < Long.MAX_VALUE){
			out.println(100000L*csumx - C);
		}else{
			out.println(-1);
		}
	}
	
	public static class Edge
	{
		public int from, to;
		public int capacity;
		public int cost;
		public int flow;
		public Edge complement;
		// public int iniflow;
		
		public Edge(int from, int to, int capacity, int cost) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
			this.cost = cost;
		}
	}
	
	public static Edge[][] compileWD(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity, -origin.cost);
			clone.flow = origin.capacity;
			clone.complement = origin;
			origin.complement = clone;
			edges.add(clone);
		}
		
		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}

	// NOT VERIFIED
	public static Edge[][] compileWU(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge back = new Edge(origin.to, origin.from, origin.capacity, origin.cost);
			edges.add(back);
		}
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity, -origin.cost);
			clone.flow = origin.capacity;
			clone.complement = origin;
			origin.complement = clone;
			edges.add(clone);
		}
		
		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}	

	
//	public static long solveMinCostFlow(Edge[][] g, int source, int sink, long all)
//	{
//		int n = g.length;
//		long mincost = 0;
//		int[] potential = new int[n];
//		
//		final int[] d = new int[n];
//		MinHeap q = new MinHeap(n);
//		while(all > 0){
//			// shortest path src->sink
//			Edge[] inedge = new Edge[n];
//			Arrays.fill(d, Integer.MAX_VALUE / 2);
//			d[source] = 0;
//			q.add(source, 0);
//			while(q.size() > 0){
//				int cur = q.argmin();
//				q.remove(cur);
//				for(Edge ne : g[cur]){
//					if(ne.capacity - ne.flow > 0){
//						int nd = d[cur] + ne.cost + potential[cur] - potential[ne.to];
//						if(d[ne.to] > nd){
//							inedge[ne.to] = ne;
//							d[ne.to] = nd;
//							q.update(ne.to, nd);
//						}
//					}
//				}
//			}
//			
//			if(inedge[sink] == null)break;
//			
//			long minflow = all;
//			long sumcost = 0;
//			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
//				if(e.capacity - e.flow < minflow)minflow = e.capacity - e.flow;
//				sumcost += e.cost;
//			}
//			mincost += minflow * sumcost;
//			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
//				e.flow += minflow;
//				e.complement.flow -= minflow;
//			}
//			
//			all -= minflow;
//			for(int i = 0;i < n;i++){
//				potential[i] += d[i];
//			}
//		}
//		return mincost;
//	}
	
	public static class DQ {
		public int[] q;
		public int n;
		protected int pt, ph;
		
		public DQ(int n){ this.n = Integer.highestOneBit(n)<<1; q = new int[this.n]; pt = ph = 0; }
		
		public void addLast(int x){ q[ph] = x; ph = ph+1&n-1; }
		public void addFirst(int x){ pt = pt+n-1&n-1; q[pt] = x; }
		public int pollFirst(){ int ret = q[pt]; pt = pt+1&n-1; return ret; }
		public int pollLast(){ ph = ph+n-1&n-1; int ret = q[ph]; return ret; }
		public int getFirst(){ return q[pt]; }
		public int getFirst(int k){ return q[pt+k&n-1]; }
		public int getLast(){ return q[ph+n-1&n-1]; }
		public int getLast(int k){ return q[ph+n-k-1&n-1]; }
		public void clear(){ pt = ph = 0; }
		public int size(){ return ph-pt+n&n-1; }
		public boolean isEmpty(){ return ph==pt; }
	}

	
	public static long solveMinCostFlowWithSPFA(Edge[][] g, int source, int sink, long all)
	{
		int n = g.length;
		long mincost = 0;
		
		final int[] d = new int[n];
		DQ q = new DQ(n);
		boolean[] inq = new boolean[n];
		while(all > 0){
			// shortest path src->sink
			Edge[] inedge = new Edge[n];
			Arrays.fill(d, Integer.MAX_VALUE / 2);
			d[source] = 0;
			q.addLast(source);
			while(!q.isEmpty()){
				int cur = q.pollFirst();
				inq[cur] = false;
				for(Edge ne : g[cur]){
					if(ne.capacity - ne.flow > 0){
						int nd = d[cur] + ne.cost;
						if(d[ne.to] > nd){
							inedge[ne.to] = ne;
							d[ne.to] = nd;
							if(!inq[ne.to]){
								q.addLast(ne.to);
								inq[ne.to] = true;
							}
						}
					}
				}
			}
			
			if(inedge[sink] == null)break;
			
			long minflow = all;
			long sumcost = 0;
			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
				if(e.capacity - e.flow < minflow)minflow = e.capacity - e.flow;
				sumcost += e.cost;
			}
			mincost += minflow * sumcost;
			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
				e.flow += minflow;
				e.complement.flow -= minflow;
			}
			
			all -= minflow;
		}
		if(all > 0)return Long.MAX_VALUE;
		return mincost;
	}

	
	int[][] nt(int n)
	{
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
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

	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
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