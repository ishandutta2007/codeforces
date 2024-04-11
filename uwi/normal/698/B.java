//package round363;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] f = na(n);
		for(int i = 0;i < n;i++)f[i]--;
		ResultCluster res = cluster(f);
		int loop = -1;
		for(int[] cy : res.cycles){
			if(cy.length == 1){
				loop = cy[0];
			}
		}
		if(loop == -1){
			out.println(res.cycles.length);
			for(int i = 0;i < res.cycles.length;i++){
				f[res.cycles[i][0]] = res.cycles[0][0];
			}
			for(int i = 0;i < n;i++){
				out.print((f[i]+1) + " ");
			}
		}else{
			out.println(res.cycles.length-1);
			for(int i = 0;i < res.cycles.length;i++){
				f[res.cycles[i][0]] = loop;
			}
			for(int i = 0;i < n;i++){
				out.print((f[i]+1) + " ");
			}
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

	
	public static ResultCluster cluster(int[] f)
	{
		int n = f.length;
		DJSet ds = new DJSet(n);
		int[] red = new int[n+1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(ds.union(i, f[i]))red[p++] = f[i];
		}
		int[] clus = new int[n]; Arrays.fill(clus, -1);
		int cidgen = 0;
		for(int i = 0;i < n;i++)if(ds.upper[i] < 0)clus[i] = cidgen++;
		for(int i = 0;i < n;i++)clus[i] = clus[ds.root(i)];
		
		int[][] cycles = new int[p][];
		int[] temp = new int[n+1];
		for(int i = 0;i < p;i++){
			temp[0] = red[i];
			int j = 1;
			for(;;j++){
				temp[j] = f[temp[j-1]];
				if(temp[j] == temp[0])break;
			}
			cycles[clus[red[i]]] = Arrays.copyOf(temp, j);
		}
		ResultCluster rc = new ResultCluster();
		rc.clus = clus;
		rc.cycles = cycles;
		return rc;
	}
	
	public static class ResultCluster {
		int[] clus;
		int[][] cycles;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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