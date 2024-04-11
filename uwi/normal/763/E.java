//package round395;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1, i};
		}
		int S = (int)Math.sqrt(n);
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0]/S != b[0]/S){
					return a[0] - b[0];
				}else{
					return a[1] - b[1];
				}
			}
		});
		int[] anss = new int[Q];
		for(int i = 0;i < Q;){
			int j = i;
			while(j < Q && qs[i][0]/S == qs[j][0]/S)j++;
			
			RestorableDisjointSet2 rds = new RestorableDisjointSet2(n, m+1);
			int con = 0;
			int p = qs[i][0]/S*S+S;
			for(int k = i;k < j;k++){
				if(qs[k][1]/S == qs[k][0]/S){
					DJSet ds = new DJSet(qs[k][1]-qs[k][0]+1);
					for(int l = qs[k][0];l <= qs[k][1];l++){
						for(int e : g[l]){
							if(qs[k][0] <= e && e <= qs[k][1]){
								ds.union(e-qs[k][0], l-qs[k][0]);
							}
						}
					}
					anss[qs[k][2]] = ds.count();
				}else{
					while(p <= qs[k][1]){
						for(int e : g[p]){
							if(e >= qs[i][0]/S*S+S && e <= p){
								if(!rds.union(p, e))con++;
							}
						}
						p++;
					}
					int h = rds.hp;
					int hcon = con;
					int z = qs[i][0]/S*S+S-1;
					while(z >= qs[k][0]){
						for(int e : g[z]){
							if(e >= z && e < p){
								if(!rds.union(z, e))hcon++;
							}
						}
						z--;
					}
					anss[qs[k][2]] = qs[k][1]-qs[k][0]+1-hcon;
					rds.revert(h);
				}
			}
			
			i = j;
		}
		for(int ans : anss){
			out.println(ans);
		}
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static class RestorableDisjointSet2 {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		public long[] hist;
		private final int offset = 1000000000;
		public int hp = 0;
		
		public RestorableDisjointSet2(int n, int m)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
//				w = new int[n];
			hist = new long[2*m];
		}
		
		public RestorableDisjointSet2(RestorableDisjointSet2 ds)
		{
			this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
			this.hist = Arrays.copyOf(ds.hist, ds.hist.length);
			this.hp = ds.hp;
		}
		
		private void rec(int x)
		{
			hist[hp++] = (long)x<<32|upper[x]+offset;
		}
		
		public int root(int x)
		{
			return upper[x] < 0 ? x : root(upper[x]);
//				if(upper[x] < 0){
//					return x;
//				}else{
//					rec(x);
//					return upper[x] = root(upper[x]);
//				}
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public boolean union(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
//					w[x] += w[y];
				rec(x);
				upper[x] += upper[y];
				rec(y);
				upper[y] = x;
			}
			return x == y;
		}
		
		public int time() { return hp; }
		
		public void revert(int to)
		{
			while(hp > to){
				upper[(int)(hist[hp-1]>>>32)] = ((int)hist[hp-1])-offset;
				hp--;
			}
		}
		
		public int count()
		{
			int ct = 0;
			for(int u : upper){
				if(u < 0)ct++;
			}
			return ct;
		}
		
		public int[][] makeUp()
		{
			int n = upper.length;
			int[][] ret = new int[n][];
			int[] rp = new int[n];
			for(int i = 0;i < n;i++){
				if(upper[i] < 0)ret[i] = new int[-upper[i]];
			}
			for(int i = 0;i < n;i++){
				int r = root(i);
				ret[r][rp[r]++] = i;
			}
			return ret;
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