//package round636;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// a->g->b->g->c
		// d(b,g)d(a,g)+d(c,g)
		for(int T = ni();T > 0;T--)go();
	}
	
	void go()
	{
		int n = ni(), m = ni();
		int A = ni()-1, B = ni()-1, C = ni()-1;
		int[] ps = na(m);
		shuffle(ps, gen);
		Arrays.sort(ps);
		
		long[] cum = new long[m+1];
		for(int i = 0;i < m;i++){
			cum[i+1] = cum[i] + ps[i];
		}
		
		int[] from = new int[m];
		int[] to = new int[m];
		for (int i = 0; i < m; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[] db = bfs(g, B);
		int[] da = bfs(g, A);
		int[] dc = bfs(g, C);
		long ans = Long.MAX_VALUE;
		for(int i = 0;i < n;i++){
			if(db[i]+da[i]+dc[i] > m)continue;
			long d = cum[db[i]] * 2 + 
					cum[db[i]+da[i]+dc[i]] - cum[db[i]];
			ans = Math.min(ans, d);
		}
		out.println(ans);
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
	
	public static int[] bfs(int[][] g, int s)
	{
		int n = g.length;
		int[] q = new int[n];
		int[] ds = new int[n];
		Arrays.fill(ds, Integer.MAX_VALUE / 2);
		int qp = 0;
		q[qp++] = s;
		ds[s] = 0;
		for(int z = 0;z < qp;z++){
			int cur = q[z];
			for(int e : g[cur]){
				if(ds[e] > ds[cur] + 1){
					ds[e] = ds[cur] + 1;
					q[qp++] = e;
				}
			}
		}
		return ds;
	}

	
	Random gen = new Random();
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
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