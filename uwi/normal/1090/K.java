import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class K2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int ptn(String x)
	{
		int ret = 0;
		for(char c : x.toCharArray()){
			ret |= 1<<c-'a';
		}
		return ret;
	}
	
	void solve()
	{
		int n = ni();
		Datum[] ds = new Datum[n];
		for(int i = 0;i < n;i++){
			char[] s = ns().toCharArray();
			int p = ptn(ns());
			int last = 0;
			for(int j = s.length-1;j >= 0;j--){
				if(p<<~(s[j]-'a')>=0){
					last = j+1;
					break;
				}
			}
			ds[i] = new Datum(new String(s, 0, last), p, i);
		}
		
		Arrays.sort(ds, new Comparator<Datum>() {
			public int compare(Datum a, Datum b) {
				if(a.ptn != b.ptn)return a.ptn - b.ptn;
				return a.s.compareTo(b.s);
			}
		});
		lds = new DisjointSetOfList(n);
		for(int i = 1;i < n;i++){
			if(ds[i].ptn == ds[i-1].ptn && ds[i].s.equals(ds[i-1].s)){
				lds.union(ds[i].id, ds[i-1].id);
			}
		}
		
		out.println(lds.count());
		for(int i = 0;i < n;i++){
			if(lds.upper[i] < 0){
				out.print(-lds.upper[i]);
				for(int cur = i;cur != -1;cur = lds.next[cur]){
					out.print(" " + (cur+1));
				}
				out.println();
			}
		}
	}
	
	static DisjointSetOfList lds;
	
	public static class DisjointSetOfList {
		public int[] upper;
		public int[] next;
		public int[] last;

		public DisjointSetOfList(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			next = new int[n];
			last = new int[n];
			Arrays.fill(next, -1);
			for(int i = 0;i < n;i++){
				last[i] = i;
			}
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
				next[last[x]] = y;
				last[x] = last[y];
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
	
	static class Datum
	{
		String s;
		int ptn;
		int id;
		public Datum(String s, int ptn, int id) {
			this.s = s;
			this.ptn = ptn;
			this.id = id;
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
	
	public static void main(String[] args) throws Exception { new K2().run(); }
	
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