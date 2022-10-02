//package round212;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), P = ni(), Q = ni();
		int[][] es = new int[m][];
		DisjointSet ds = new DisjointSet(n);
		
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1, ni()};
			ds.union(es[i][0], es[i][1], es[i][2]);
		}
		
		PriorityQueue<long[]> pq = new PriorityQueue<long[]>(100001, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				return Long.signum(a[1] - b[1]);
			}
		});
		int nclus = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				pq.add(new long[]{i, ds.w[i]});
				nclus++;
			}
		}
		
		int[][] hist = new int[P][];
		int i;
		for(i = 0;i < P && nclus > Q;i++){
			if(pq.size() >= 2){
				long[] one = pq.poll();
				long[] two = pq.poll();
				ds.union((int)one[0], (int)two[0], Math.min(1000000000L, one[1]+two[1]+1));
				hist[i] = new int[]{(int)one[0], (int)two[0]};
				long[] res = new long[]{ds.root((int)one[0]), ds.w[ds.root((int)one[0])]};
				pq.add(res);
				nclus--;
			}else{
				break;
			}
		}
		if(nclus == Q){
			inner:
			for(int j = 0;j < n;j++){
				if(ds.upper[j] <= -2){
					for(int k = 0;k < n;k++){
						if(k != j && ds.equiv(k, j)){
							for(;i < P;i++){
								hist[i] = new int[]{j, k};
							}
							break inner;
						}
					}
				}
			}
		}
		
		if(i < P || nclus != Q){
			out.println("NO");
		}else{
			out.println("YES");
			for(int j = 0;j < P;j++){
				out.println((hist[j][0]+1) + " " + (hist[j][1]+1));
			}
		}
	}
	
	public static class DisjointSet {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		public long[] w;
		
		public DisjointSet(int n)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
			w = new long[n];
		}
		
		public int root(int x)
		{
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public boolean union(int x, int y, long plus)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
				w[x] += w[y];
				upper[x] += upper[y];
				upper[y] = x;
			}
			w[x] += plus;
			return x == y;
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