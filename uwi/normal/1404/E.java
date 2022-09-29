//package round668;
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
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		List<Edge> es = new ArrayList<>();
		int src = n*m*3, sink = src + 1;
		int p = n*m;
		int h = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '#'){
					h++;
//					es.add(new Edge(src, i*m+j, 0));
//					es.add(new Edge(i*m+j, sink, 0));
					if(j+1 < m && map[i][j+1] == '#'){
						es.add(new Edge(p, i*m+j, 99999999));
						es.add(new Edge(p, i*m+j+1, 99999999));
						es.add(new Edge(src, p, 1));
						p++;
					}
					if(i+1 < n && map[i+1][j] == '#'){
						es.add(new Edge(i*m+j, p, 99999999));
						es.add(new Edge((i+1)*m+j, p, 99999999));
						es.add(new Edge(p, sink, 1));
						p++;
					}
				}
			}
		}
//		tr(hlpp(compileWD(sink+1, es), src, sink));
//		tr(h);
//		tr(p-n*m);
		out.println(h - ((p-n*m)-hlpp(compileWD(sink+1, es), src, sink)));
	}

	public static class Edge
	{
		public int from, to;
		public long capacity;
		public long flow;
		public Edge complement;
		public boolean cloned;

		public Edge(int from, int to, long capacity) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
		}
	}

	public static void reset(Edge[][] g)
	{
		for(Edge[] row : g){
			for(Edge e : row){
				e.flow = e.cloned ? e.capacity : 0;
			}
		}
	}

	public static Edge[][] compileWD(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity);
			clone.flow = origin.capacity - origin.flow;
			clone.complement = origin;
			clone.cloned = true;
			origin.complement = clone;
			edges.add(clone);
		}

		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}

	public static Edge[][] compileWU(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity*2);
			origin.flow = origin.capacity;
			clone.flow = origin.capacity;
			clone.complement = origin;
			clone.cloned = true;
			origin.complement = clone;
			origin.capacity *= 2;
			edges.add(clone);
		}

		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}

	private static void add(int[] first, int[] next, int level, int x)
	{
		int n = first.length;
		if(level < n){
			next[x] = first[level];
			first[level] = x;
		}
	}

	private static int poll(int[] first, int[] next, int level)
	{
		int ret = first[level];
		if(ret != -1){
			first[level] = next[ret];
			next[ret] = -1;
		}
		return ret;
	}

	private static void add(int[] first, int[] next, int[] prev, int level, int x)
	{
		next[x] = first[level];
		if(next[x] != -1)prev[next[x]] = x;
		first[level] = x;
	}

	private static void remove(int[] first, int[] next, int[] prev, int level, int x)
	{
		int p = prev[x];
		int n = next[x];
		if(p == -1)first[level] = n;
		if(p != -1)next[p] = n;
		if(n != -1)prev[n] = p;
		prev[x] = next[x] = -1;
	}

	private static int labelGrobally(Edge[][] g, int source, int sink, int[] label,
	                                 int[] activeFirst, int[] activeNext,
	                                 int[] gapFirst, int[] gapNext, int[] gapPrev,
	                                 long[] excess)
	{
		Arrays.fill(activeFirst, -1);
		Arrays.fill(activeNext, -1);
		Arrays.fill(gapFirst, -1);
		Arrays.fill(gapNext, -1);
		Arrays.fill(gapPrev, -1);
		int n = g.length;

		Arrays.fill(label, n);
		label[sink] = 0;
		int[] q = new int[n];
		int p = 0;
		q[p++] = sink;
		for(int z = 0;z < p;z++){
			int cur = q[z];
			for(Edge e : g[cur]){
				if(e.flow > 0 && label[e.to] > label[e.from] + 1){
					label[e.to] = label[e.from] + 1;
					q[p++] = e.to;
				}
			}
		}
		int highest = 0;
		for(int i = 0;i < n;i++){
			if(label[i] < n){
				if(excess[i] > 0){
					highest = Math.max(highest, label[i]);
					add(activeFirst, activeNext, label[i], i);
				}
				add(gapFirst, gapNext, gapPrev, label[i], i);
			}
		}
		return highest;
	}

	public static long hlpp(Edge[][] g, int source, int sink)
	{
		long big = Long.MAX_VALUE / 2;
		int n = g.length;
		int[] label = new int[n];
		long[] excess = new long[n];
		excess[source] = big;
		excess[sink] = -big;

		int[] activeFirst = new int[n];
		int[] activeNext = new int[n];
		int[] gapFirst = new int[n];
		int[] gapNext = new int[n];
		int[] gapPrev = new int[n];

		int highest = labelGrobally(g, source, sink, label, activeFirst, activeNext, gapFirst, gapNext, gapPrev, excess);

		// flow (src, *)
		for(Edge se : g[source]){
			if(excess[se.to] == 0){
				add(activeFirst, activeNext, label[se.to], se.to);
				if(label[se.to] < n)highest = Math.max(highest, label[se.to]);
			}
			push(se, excess);
		}

		int nUpdate = 0;
		for(;highest >= 0;highest--){
			while(activeFirst[highest] != -1){
				int cur = poll(activeFirst, activeNext, highest);
				for(Edge e : g[cur]){
					if(excess[cur] == 0)break;
					if(label[e.from] == label[e.to] + 1 && e.flow < e.capacity){
						if(excess[e.to] == 0)add(activeFirst, activeNext, label[e.to], e.to);
						push(e, excess);
					}
				}
				if(excess[cur] > 0){
					int oldh = label[cur];
					remove(gapFirst, gapNext, gapPrev, label[cur], cur);
					relabel(cur, g, label);
					if(label[cur] < n){
						add(gapFirst, gapNext, gapPrev, label[cur], cur);
						highest = label[cur];
					}

					if(gapFirst[oldh] == -1){
						// gap-relabelling
						for(int h = oldh+1;h <= highest;h++){
							for(int y = gapFirst[h];y != -1;y = gapNext[y]){
								label[y] = n;
								gapNext[y] = gapPrev[y] = -1;
							}
							gapFirst[h] = -1;
						}
						highest = oldh-1;
					}else if(label[cur] < n){
						nUpdate++;
						add(activeFirst, activeNext, highest, cur);
					}
				}
				if(nUpdate > 4*n){
					nUpdate = 0;
					// verify label
//					for(int u = 0;u < n;u++){
//						for(int x = gapFirst[u];x != -1;x = gapNext[u]){
//							if(label[x] != u)throw new RuntimeException();
//							if(gapPrev[x] != -1){
//								if(gapNext[gapPrev[x]] != x){
//									throw new RuntimeException();
//								}
//							}else{
//								if(gapFirst[u] != x){
//									throw new RuntimeException();
//								}
//							}
//						}
//					}
					highest = labelGrobally(g, source, sink, label, activeFirst, activeNext, gapFirst, gapNext, gapPrev, excess);
				}
			}
		}
		return excess[sink] + big;
	}

	private static void push(Edge e, long[] excess)
	{
		long f = Math.min(excess[e.from], e.capacity - e.flow);
		e.flow += f;
		e.complement.flow -= f;
		excess[e.from] -= f;
		excess[e.to] += f;
	}

	private static void relabel(int cur, Edge[][] g, int[] label)
	{
		int n = g.length;
		int min = n;
		for(Edge e : g[cur]){
			if(e.flow < e.capacity)min = Math.min(min, label[e.to] + 1);
		}
		label[cur] = min;
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