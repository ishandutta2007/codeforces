//package educational.round43;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n1 = ni(), n2 = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] deg1 = new int[n1];
		int[] deg2 = new int[n2];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			deg1[from[i]]++;
			deg2[to[i]]++;
		}
		int mindeg = 99999999;
		for(int i = 0;i < n1;i++){
			mindeg = Math.min(mindeg, deg1[i]);
		}
		for(int i = 0;i < n2;i++){
			mindeg = Math.min(mindeg, deg2[i]);
		}
		
		int[] ret = new int[m];
		List<Edge> es = new ArrayList<>();
		int src = n1+n2, sink = src+1;
		for(int i = 0;i < n1;i++){
			es.add(new Edge(src, i, 0, 0));
			es.add(new Edge(src, i, 9999, 1));
		}
		for(int i = 0;i < n2;i++){
			es.add(new Edge(i+n1, sink, 0, 0));
			es.add(new Edge(i+n1, sink, 9999, 1));
		}
		for(int i = 0;i < m;i++){
			es.add(new Edge(from[i], n1+to[i], 1, 0, i));
		}
		Edge[][] g = compileWD(sink+1, es);
		for(int z = 0;z <= mindeg;z++){
			if(z == 0){
				out.println(0);
				continue;
			}
			for(int i = 0;i < g.length;i++){
				for(Edge e : g[i]){
					if(e.from == src || e.to == sink){
						e.capacity = z;
						e.complement.capacity = z;
						e.complement.flow++;
					}
				}
			}
			
			solveMinCostFlowWithSPFA(g, src, sink, m);
			int p = 0;
			for(int i = 0;i < n1;i++){
				for(Edge e : g[i]){
					if(e.label != -1 && e.flow > 0){
						ret[p++] = e.label+1;
					}
				}
			}
			out.print(p);
			for(int i = 0;i < p;i++)out.print(" " + ret[i]);
			out.println();
		}
		
	}
	
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
			if(sumcost >= 2)break;
			mincost += minflow * sumcost;
			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
				e.flow += minflow;
				e.complement.flow -= minflow;
			}
			
			all -= minflow;
		}
		return mincost;
	}
	
	public static class Edge
	{
		public int from, to;
		public int capacity;
		public int cost;
		public int flow;
		public int label;
		public Edge complement;
		// public int iniflow;
		
		public Edge(int from, int to, int capacity, int cost) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
			this.cost = cost;
			this.label = -1;
		}

		public Edge(int from, int to, int capacity, int cost, int label) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
			this.cost = cost;
			this.label = label;
		}

		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", capacity="
					+ capacity + ", cost=" + cost + "]";
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

	public static long solveMinCostFlow(Edge[][] g, int source, int sink, long all)
	{
		int n = g.length;
		long mincost = 0;
		int[] potential = new int[n];
		
		final int[] d = new int[n];
		MinHeap q = new MinHeap(n);
		while(all > 0){
			// shortest path src->sink
			Edge[] inedge = new Edge[n];
			Arrays.fill(d, Integer.MAX_VALUE / 2);
			d[source] = 0;
			q.add(source, 0);
			while(q.size() > 0){
				int cur = q.argmin();
				q.remove(cur);
				for(Edge ne : g[cur]){
					if(ne.capacity - ne.flow > 0){
						int nd = d[cur] + ne.cost + potential[cur] - potential[ne.to];
						if(d[ne.to] > nd){
							inedge[ne.to] = ne;
							d[ne.to] = nd;
							q.update(ne.to, nd);
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
			if(sumcost >= 2)break;
			mincost += minflow * sumcost;
			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
				e.flow += minflow;
				e.complement.flow -= minflow;
			}
			
			all -= minflow;
			for(int i = 0;i < n;i++){
				potential[i] += d[i];
			}
		}
		return mincost;
	}
	
	public static class MinHeap {
		public int[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static int INF = Integer.MAX_VALUE;
		
		public MinHeap(int m)
		{
			n = m+2;
			a = new int[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public int add(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public int update(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				int o = a[ret];
				a[ret] = x;
				up(ret);
				down(ret);
//				if(a[ret] > o){
//					up(ret);
//				}else{
//					down(ret);
//				}
			}
			return x;
		}
		
		public int remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			int ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public int min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				int d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					int d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
	}

	
	void run() throws Exception
	{
//		int n = 44, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		sb.append(n*n + " ");
////		for (int i = 0; i < n; i++) {
////			sb.append((i+1) + " " + (i+1) + "\n");
////		}
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < n;j++){
//				sb.append((i+1) + " " + (j+1) + "\n");
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
	
	public static void main(String[] args) throws Exception { new F3().run(); }
	
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