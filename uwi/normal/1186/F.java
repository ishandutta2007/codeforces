//package round571;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static class Edge
	{
		int a, b;
		boolean ved;
		boolean red;

		public Edge(int f, int t) {
			this.a = f;
			this.b = t;
		}
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		List<Deque<Edge>> g = new ArrayList<>();
		for(int i = 0;i < n;i++){
			g.add(new ArrayDeque<>());
		}
		int[] deg = new int[n];
		List<Edge> es = new ArrayList<>();
		for(int i = 0;i < m;i++){
			int a = ni()-1, b = ni()-1;
			Edge e = new Edge(a, b);
			es.add(e);
			g.get(a).add(e);
			g.get(b).add(e);
			deg[a]++;
			deg[b]++;
		}
		
		for(int i = 0;i < n;i++){
			while(!g.get(i).isEmpty()){
				Edge last = null;
				int cur = i;
				int len = 0;
				while(true){
					Edge ne = null;
					while(!g.get(cur).isEmpty()){
						ne = g.get(cur).pollFirst();
						if(ne.ved){
							ne = null;
							continue;
						}
						break;
					}
					
					if(ne == null){
						if(len % 2 == 0 && len >= 2){
							last.red = false;
						}
						break;
					}
//					tr(ne.a, ne.b, ne.ved, ne.red);
					
					ne.ved = true;
					if(len % 2 == 1){
						ne.red = true;
					}
					cur = cur^ne.a^ne.b;
					len++;
					last = ne;
				}
			}
		}
		
		int rem = 0;
		for(Edge e : es){
			if(!e.red){
				rem++;
			}
		}
		assert rem <= (n+m+1)/2;
		out.println(rem);
		int[] ac = new int[n];
		for(Edge e : es){
			if(!e.red){
				out.println((e.a+1) + " "+ (e.b+1));
				ac[e.a]++;
				ac[e.b]++;
			}
		}
		
		for(int i = 0;i < n;i++){
			assert (deg[i]+1)/2 <= ac[i];
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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