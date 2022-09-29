//package round6;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Edge
	{
		int from;
		int to;
		long f;
		public Edge(int from, int to, long f) {
			this.from = from;
			this.to = to;
			this.f = f;
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		List<Queue<Edge>> g = new ArrayList<>();
		List<Queue<Edge>> ig = new ArrayList<>();
		for(int i = 0;i < n;i++){
			g.add(new ArrayDeque<>());
			ig.add(new ArrayDeque<>());
		}
		for(int i = 0;i < m;i++){
			int x = ni()-1, y = ni()-1, w = ni();
			Edge e = new Edge(x, y, w);
			g.get(x).add(e);
			ig.get(y).add(e);
		}
		Queue<Integer> q = new ArrayDeque<>();
		for(int i = 0;i < n;i++)q.add(i);
		while(!q.isEmpty()){
			int cur = q.poll();
			while(!g.get(cur).isEmpty() && !ig.get(cur).isEmpty()){
				Edge ge = g.get(cur).peek();
				if(ge.f == 0){
					g.get(cur).poll();
					continue;
				}
				Edge ige = ig.get(cur).peek();
				if(ige.f == 0){
					ig.get(cur).poll();
					continue;
				}
				long f = Math.min(ge.f, ige.f);;
				ge.f -= f;
				ige.f -= f;
				if(ige.from != ge.to){
					Edge ne = new Edge(ige.from, ge.to, f);
					g.get(ne.from).add(ne);
					ig.get(ne.to).add(ne);
					q.add(ne.from);
					q.add(ne.to);
				}
			}
		}
		List<String> rets = new ArrayList<>();
		for(int i = 0;i < n;i++){
			Map<Integer, Edge> map = new HashMap<>();
			for(Edge e : g.get(i)){
				if(e.f == 0)continue;
				if(map.containsKey(e.to)){
					map.get(e.to).f += e.f;
				}else{
					map.put(e.to, e);
				}
			}
			for(int key : map.keySet()){
				rets.add((i+1) + " " + (key+1) + " " + map.get(key).f);
			}
		}
		out.println(rets.size());
		for(String line : rets){
			out.println(line);
		}
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