//package round616;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[] s = ns(n);
		int[][] f = new int[n][2];
		int[] fp = new int[n];
		for(int i = 0;i < m;i++){
			for(int q = ni();q > 0;q--){
				int x = ni()-1;
				f[x][fp[x]++] = i;
			}
		}
		DJSet ds = new DJSet(2*m);
		for(int i = 0;i < m;i++){
			ds.numt[i+m] = 1;
		}
		int ans = 0;
		for(int i = 0;i < n;i++){
			if(fp[i] == 0){
			}else if(fp[i] == 1){
				int id = f[i][0];
				if(ds.must[ds.root(id)] || ds.must[ds.root(id+m)]){
				}else{
					ans -= Math.min(ds.numt[ds.root(id)], ds.numt[ds.root(id+m)]);
					if(s[i] == '0'){
						ds.must[ds.root(id+m)] = true;
						ans += ds.numt[ds.root(id+m)];
					}else{
						ds.must[ds.root(id)] = true;
						ans += ds.numt[ds.root(id)];
					}
				}
			}else if(fp[i] == 2){
				int id1 = f[i][0];
				int id2 = f[i][1];
				if(s[i] == '0'){
					if(!ds.equiv(id1, id2+m)){
						ans -= go(id1, m, ds);
						ans -= go(id2, m, ds);
						ds.union(id1, id2+m);
						ds.union(id1+m, id2);
						ans += go(id1, m, ds);
					}
				}else{
					if(!ds.equiv(id1, id2)){
						ans -= go(id1, m, ds);
						ans -= go(id2, m, ds);
						ds.union(id1, id2);
						ds.union(id1+m, id2+m);
						ans += go(id1, m, ds);
					}
				}
			}
			out.println(ans);
		}
	}
	
	int go(int id, int m, DJSet ds)
	{
		if(ds.must[ds.root(id)]){
			return ds.numt[ds.root(id)];
		}else if(ds.must[ds.root(id+m)]){
			return ds.numt[ds.root(id+m)];
		}else{
			return Math.min(ds.numt[ds.root(id)], ds.numt[ds.root(id+m)]);
		}
	}
	
	public static class DJSet {
		public int[] upper;
		public boolean[] must;
		public int[] numt;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			must = new boolean[n];
			numt = new int[n];
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
				numt[x] += numt[y];
				must[x] |= must[y];
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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