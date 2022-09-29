//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Helvetic2017N {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		int[] b = na(n);
		
		List<Edge> es = new ArrayList<>();
		int src = n, sink = n+1;
		for(int i = 0;i < n;i++){
			es.add(new Edge(src, i, 1, a[i]));
			es.add(new Edge(i, sink, 1, b[i]));
			if(i+1 < n)es.add(new Edge(i, i+1, 9999, 0));
		}
		out.println(solveMinCostFlow(compileWD(sink+1, es), src, sink, K));
	}
	
	public static class Edge
	{
		public int from, to;
		public int capacity;
		public long cost;
		public int flow;
		public Edge complement;
		// public int iniflow;
		
		public Edge(int from, int to, int capacity, long cost) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
			this.cost = cost;
		}

		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", capacity="
					+ capacity + ", cost=" + cost + "]";
		}
	}
	
	public static long addNegativeEdge(List<Edge> edges, Edge e, int src, int sink)
	{
		if(e.cost > 0){
			edges.add(e);
			return 0;
		}else{
			e.cost = -e.cost;
			edges.add(new Edge(src, e.to, e.capacity, 0));
			edges.add(new Edge(e.from, sink, e.capacity, 0));
					
			int d = e.from; e.from = e.to; e.to = d;
			edges.add(e);
			return (long)e.capacity * -e.cost;
		}
	}
	
	// TODO test
	public static long addMinCapacityConstraintEdge(List<Edge> edges, Edge e, int minCapacity, int src, int sink)
	{
		e.capacity -= minCapacity;
		edges.add(new Edge(src, e.to, minCapacity, 0));
		edges.add(new Edge(e.from, sink, minCapacity, 0));
		return (long)minCapacity * e.cost;
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
	
	public static class MinHeapL {
		public long[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static long INF = Long.MAX_VALUE;
		
		public MinHeapL(int m)
		{
			n = Integer.highestOneBit((m+1)<<1);
			a = new long[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public long add(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public long update(int ind, long x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				a[ret] = x;
				up(ret);
				down(ret);
			}
			return x;
		}
		
		public long remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			long ret = a[rem];
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
		
		public long min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					long d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
		}
	}

	public static long solveMinCostFlow(Edge[][] g, int source, int sink, long all)
	{
		int n = g.length;
		long mincost = 0;
		long[] potential = new long[n];
		
		final long[] d = new long[n];
		MinHeapL q = new MinHeapL(n);
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
						long nd = d[cur] + ne.cost + potential[cur] - potential[ne.to];
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
	
	// negative is OK.
	public static long solveMinCostFlowWithSPFA(Edge[][] g, int source, int sink, long all)
	{
		int n = g.length;
		long mincost = 0;
		
		final long[] d = new long[n];
		DQ q = new DQ(n);
		boolean[] inq = new boolean[n];
		while(all > 0){
			// shortest path src->sink
			Edge[] inedge = new Edge[n];
			Arrays.fill(d, Long.MAX_VALUE / 2);
			d[source] = 0;
			q.addLast(source);
			while(!q.isEmpty()){
				int cur = q.pollFirst();
				inq[cur] = false;
				for(Edge ne : g[cur]){
					if(ne.capacity - ne.flow > 0){
						long nd = d[cur] + ne.cost;
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
		return mincost;
	}
	
	
	// neagtive is OK, and simple but maybe slower.
	public static long solveMinCostFlowWithBellmanFord(Edge[][] g, int source, int sink, long all)
	{
		int n = g.length;
		long mincost = 0;
		
		final long[] d = new long[n];
		while(all > 0){
			// shortest path src->sink
			Edge[] inedge = new Edge[n];
			Arrays.fill(d, Long.MAX_VALUE / 2);
			d[source] = 0;
			
			int nease = 0;
			for(;;nease++){
				boolean changed = false;
				for(Edge[] row : g){
					for(Edge e : row){
						if(e.capacity - e.flow > 0){
							long nd = d[e.from] + e.cost;
							if(nd < d[e.to]){
								d[e.to] = nd;
								inedge[e.to] = e;
								changed = true;
							}
						}
					}
				}
				if(!changed)break;
				if(nease == n-1){
					// there are negative circuits.
					throw new RuntimeException();
				}
			}
			
			if(inedge[sink] == null)break;
			
			long minflow = all;
			long sumcost = 0;
			boolean fromSource = false;
			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
				if(e.capacity - e.flow < minflow)minflow = e.capacity - e.flow;
				sumcost += e.cost;
				if(e.from == source)fromSource = true;
			}
			if(!fromSource)break;
				
			mincost += minflow * sumcost;
			for(Edge e = inedge[sink];e != null;e = inedge[e.from]){
				e.flow += minflow;
				e.complement.flow -= minflow;
			}
			
			all -= minflow;
		}
		return mincost;
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
	
	public static void main(String[] args) throws Exception { new Helvetic2017N().run(); }
	
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