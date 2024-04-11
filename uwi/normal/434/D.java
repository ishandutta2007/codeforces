//package round248;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(3);
		}
		int[][] lr = new int[n][];
		for(int i = 0;i < n;i++){
			lr[i] = na(2);
		}
		int[][] con = new int[m][];
		for(int i = 0;i < m;i++){
			con[i] = new int[]{ni()-1, ni()-1, ni()};
		}
		
		int L = 250000;
		
		// [0,202*n)
		int src = 202*n;
		int sink = 202*n+1;
		int H = 100;
		int infty = (L+1)*700;
		List<Edge> edges = new ArrayList<Edge>();
		for(int i = 0;i < n;i++){
			edges.add(new Edge(src, i*202+lr[i][0]+H, infty));
			for(int j = lr[i][0];j <= lr[i][1];j++){
				edges.add(new Edge(i*202+j+H, i*202+j+H+1, L-(co[i][0]*j*j+co[i][1]*j+co[i][2])));
			}
			edges.add(new Edge(i*202+lr[i][1]+1+H, sink, infty));
		}
		for(int i = 0;i < m;i++){
			int f = con[i][0], t = con[i][1], d = con[i][2];
			for(int j = lr[f][0];j <= lr[f][1]+1;j++){
				if(j-d >= lr[t][0] && j-d <= lr[t][1]+1){
					edges.add(new Edge(f*202+j+H, t*202+j-d+H, infty));
				}
			}
		}
		out.println(L*n-maximumFlowDinic(compileWD(sink+1, edges), src, sink));
	}
	
	public static String toDOT(int[][][] g)
	{
		StringBuilder sb = new StringBuilder();
		int n = g.length;
		sb.append("digraph{\n");
		sb.append("graph[rankdir=LR];\n");
		sb.append("node[shape=circle];\n");
		for(int i = 0;i < n;i++){
			for(int[] e : g[i]){
				sb.append("\"" + i + "\"");
				sb.append("->");
				sb.append("\"" + e[0] + "\"");
				sb.append("[label=\"" + e[1] + "\"];\n");
			}
		}
		sb.append("}\n");
		return sb.toString();
	}
	
	public static String toDOT(int[][][] g, int[][] F)
	{
		StringBuilder sb = new StringBuilder();
		int n = g.length;
		sb.append("digraph{\n");
		sb.append("graph[rankdir=LR];\n");
		sb.append("node[shape=circle];\n");
		for(int i = 0;i < n;i++){
			for(int j = 0;j < g[i].length;j++){
				int[] e = g[i][j];
				int flow = F[i][j];
				sb.append("\"" + i + "\"");
				sb.append("->");
				sb.append("\"" + e[0] + "\"");
				sb.append("[label=\"" + flow + "/" + e[1] + "\"");
				if(flow == 0){
					sb.append(", style = dashed");
				}else{
					if(flow == e[1])sb.append(", style = bold");
				}
				sb.append("];\n");
			}
		}
		sb.append("}\n");
		return sb.toString();
	}
	
	public static class Edge
	{
		public int from, to;
		public int capacity;
		public int flow;
		public Edge complement;
		
		public Edge(int from, int to, int capacity) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
		}
	}
	
	public static Edge[][] compileWD(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity);
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
	
	public long maximumFlowDinic(Edge[][] g, int source, int sink)
	{
		int n = g.length;
		int[] d = new int[n]; // distance
		int[] q = new int[n]; // queue for BFS
		long ret = 0;
		int[] stack = new int[n];
		long[] lefts = new long[n]; // left to flow
		int[] probe = new int[n]; // search pointer
		while(true){
			Arrays.fill(d, -1);
			q[0] = source;
			int r = 1;
			d[source] = 0;
			
			for(int v = 0;v < r;v++){
				int cur = q[v];
				for(int i = 0;i < g[cur].length;i++){
					Edge ne = g[cur][i];
					if(d[ne.to] == -1 && ne.capacity - ne.flow > 0) {
						q[r++] = ne.to;
						d[ne.to] = d[cur] + 1;
					}
				}
			}
			if(d[sink] == -1)break;
			
			for(int i = 0;i < n;i++)probe[i] = g[i].length;
			int sp = 0;
			stack[sp] = source;
			lefts[sp] = Long.MAX_VALUE;
			sp++;
			
			long delta = 0;
			while(sp > 0){
				int cur = stack[sp-1];
				if(cur == sink){
					long fl = lefts[sp-1];
					delta += fl;
					for(int i = 0;i < sp-1;i++){
						int lcur = stack[i];
						Edge e = g[lcur][probe[lcur]];
						lefts[i] -= fl;
						e.flow += fl;
						e.complement.flow -= fl;
					}
					sp--;
				}
				if(probe[cur] > 0){
					Edge ne = g[cur][--probe[cur]];
					if(d[ne.to] == d[cur]+1 && ne.capacity - ne.flow > 0){
						lefts[sp] = Math.min(lefts[sp-1], ne.capacity - ne.flow);
						stack[sp] = ne.to;
						sp++;
					}
				}else{
					sp--;
				}
			}
			ret += delta;
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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