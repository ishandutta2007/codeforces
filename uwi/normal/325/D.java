//package memsql.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "5 6 25 1 6 2 4 3 4 4 3 5 2 2 6 3 1 5 1 1 5 2 1 1 1 4 2 1 4 1 2 4 1 5 5 2 5 5 6 3 2 4 5 4 4 5 4 2 2 1 3 4 6";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		if(m == 1){
			out.println(0);
			return;
		}
		
		boolean[][] b = new boolean[n][2*m];
		DJSet ds = new DJSet(2*n*m);
		int ok = 0;
		outer:
		for(int q = 0;q < Q;q++){
			int r = ni()-1, c = ni()-1;
			int[] clusL = new int[9];
			int[] clusR = new int[9];
			int pl = 0, pr = 0;
			for(int i = -1;i <= 1;i++){
				for(int j = -1;j <= 1;j++){
					{
						int nr = r + i, nc = c + j;
						if(nc >= 2*m)nc -= 2*m;
						if(nc < 0)nc += 2*m;
						if(nr >= 0 && nr < n && b[nr][nc]){
							clusL[pl++] = ds.root(nr*2*m+nc);
						}
					}
					{
						int nr = r + i, nc = c + m + j;
						if(nc >= 2*m)nc -= 2*m;
						if(nc < 0)nc += 2*m;
						if(nr >= 0 && nr < n && b[nr][nc]){
							clusR[pr++] = ds.root(nr*2*m+nc);
						}
					}
				}
			}
			Arrays.sort(clusL, 0, pl);
			for(int i = 0;i < pr;i++){
				if(Arrays.binarySearch(clusL, 0, pl, clusR[i]) >= 0){
//					out.println(false);
					continue outer;
				}
			}
			b[r][c] = b[r][c+m] = true;
			for(int i = 0;i < pl;i++)ds.union(r*2*m+c, clusL[i]);
			for(int i = 0;i < pr;i++)ds.union(r*2*m+c+m, clusR[i]);
//			out.println(true);
			ok++;
		}
		
		out.println(ok);
	}
	
	public static void tf(boolean[][] b)
	{
		for(boolean[] r : b) {
			char[] s = new char[r.length];
			for(int i = 0;i < r.length;i++)s[i] = r[i]?'O':'X';
			System.out.println(new String(s));
		}
		System.out.println();
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public boolean union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;} return x == y;} public int count(){ int ct = 0; for(int u : upper)if(u < 0)ct++; return ct; }}
	
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