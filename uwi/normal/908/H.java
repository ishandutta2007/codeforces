//package goodbye2017;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class H3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] map = nm(n,n);
		DJSet ds = new DJSet(n);
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(map[i][j] == 'A'){
					ds.union(i, j);
				}
			}
		}
		// consistency
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(ds.equiv(i, j)){
					if(map[i][j] == 'X'){
						out.println(-1);
						return;
					}
				}
			}
		}
		
		int[] imap = new int[n];
		Arrays.fill(imap, -1);
		int p = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < -1){
				imap[i] = p++;
			}
		}
		int[] g = new int[p];
		Arrays.fill(g, (1<<p)-1);
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == 'X'){
					int ri = imap[ds.root(i)];
					int rj = imap[ds.root(j)];
					if(ri != -1 && rj != -1 && ri != rj){
						g[ri] &= ~(1<<rj);
						g[rj] &= ~(1<<ri);
					}
				}
			}
		}
		
		out.println(n-1+minimumCliqueCover(g));
	}
	
	public int minimumCliqueCover(int[] g)
	{
		if(g.length == 0)return 0;
		int n = g.length;
		int[] clique = new int[1<<n];
		
		int[] co = new int[1<<n];
		co[0] = 1;
		for(int i = 1;i < 1<<n;i++){
			co[i] = -co[i&i-1];
		}
		
		outer:
		for(int i = 0;i < 1<<n;i++){
			for(int j = 0;j < n;j++){
				if(i<<~j<0){
					if((g[j]&i) != i)continue outer;
				}
			}
			clique[i]++;
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 1<<n;j++){
				if(j<<~i>=0){
					clique[j|1<<i] += clique[j];
				}
			}
		}
		
		int[] temp = new int[1<<n];
		Arrays.fill(temp, 1);
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < 1<<n;j++){
				temp[j] = temp[j] * clique[j];
			}
			
			int s = 0;
			for(int j = 0;j < 1<<n;j++){
				s += co[j] * temp[j];
			}
			if(s != 0){
				return i;
			}
		}
		return -1;
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new H3().run(); }
	
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