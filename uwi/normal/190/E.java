//package round120;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m= ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] clus = decompose(g);
		out.println(clus.length);
		for(int[] c : clus){
			out.print(c.length);
			for(int v : c){
				out.print(" " + (v+1));
			}
			out.println();
		}
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
	
	public static int[][] decompose(int[][] g)
	{
		int n = g.length;
		int mindeg = n+1;
		int arg = -1;
		for(int i = 0;i < n;i++){
			if(g[i].length < mindeg){
				mindeg = g[i].length;
				arg = i;
			}
		}
		int[] garg = Arrays.copyOf(g[arg], g[arg].length);
		Arrays.sort(garg);
		
		boolean[][] h = filterDense(g, garg);
		int m = h.length;
		// get complement
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++){
				if(i != j)h[i][j] = !h[i][j];
			}
		}
		
		int[] clus = classify(h);
		
		boolean[] connectedWithZero = new boolean[m];
		for(int i = 0;i < m;i++){
			int x = garg[i];
			if(connectedWithZero[clus[i]])continue;
			if(g[x].length < n-m){
				connectedWithZero[clus[i]] = true;
			}else{
				int disconnectedWithOuterThanH = 0;
				for(int e : g[x]){
					if(Arrays.binarySearch(garg, e) < 0){
						disconnectedWithOuterThanH++;
					}
				}
				connectedWithZero[clus[i]] = disconnectedWithOuterThanH < n-m;
			}
		}
		
		int[][] ret = new int[n][];
		ret[0] = new int[n];
		int p = 0, q = 0;
		for(int i = 0;i < n;i++){
			if(p < garg.length && garg[p] == i){
				if(connectedWithZero[clus[p]]){
					ret[0][q++] = i;
				}
				p++;
			}else{
				ret[0][q++] = i;
			}
		}
		ret[0] = Arrays.copyOf(ret[0], q);
		int retgen = 1;
		int[][] b = makeBuckets(clus);
		for(int i = 0;i < b.length;i++){
			if(b[i].length > 0 && !connectedWithZero[i]){
				for(int j = 0;j < b[i].length;j++){
					b[i][j] = garg[b[i][j]];
				}
				ret[retgen++] = b[i];
			}
		}
		return Arrays.copyOf(ret, retgen);
	}
	
	static int[] classify(boolean[][] g)
	{
		int n = g.length;
		int[] q = new int[n];
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int clusgen = 0;
		for(int i = 0;i < n;i++){
			if(clus[i] == -1){
				int qp = 0;
				clus[i] = clusgen;
				q[qp++] = i;
				for(int r = 0;r < qp;r++){
					int cur = q[r];
					for(int j = 0;j < n;j++){
						if(g[cur][j] && clus[j] == -1){
							clus[j] = clusgen;
							q[qp++] = j;
						}
					}
				}
				clusgen++;
			}
		}
		return clus;
	}
	
	static boolean[][] filterDense(int[][] g, int[] valids)
	{
		boolean[][] h = new boolean[valids.length][valids.length];
		int m = valids.length;
		Map<Integer, Integer> gtoh = new HashMap<>();
		for(int i = 0;i < m;i++)gtoh.put(valids[i], i);
		
		for(int i = 0;i < m;i++){
			for(int e : g[valids[i]]){
				if(gtoh.containsKey(e))h[i][gtoh.get(e)] = true;
			}
		}
		
		return h;
	}
	
	public static int[][] makeBuckets(int[] a)
	{
		int n = a.length;
		int sup = 0;
		for(int v : a)sup = Math.max(sup, v);
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
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