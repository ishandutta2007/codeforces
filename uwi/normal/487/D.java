//package round278;
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
	
	void solve()
	{
		int n = ni(), m = ni(), q = ni();
		char[][] map = nm(n,m);
		int s = Math.max(1, (int)Math.sqrt(n)/3);
		int[][][] end = new int[n][m][2];
		for(int i = 0;i < n;i+=s){
			analyze(i, Math.min(i+s-1, n-1), map, end);
		}
		
		int[] passed = new int[n];
		for(int z = 0;z < q;z++){
			char t = nc();
			if(t == 'A'){
				int r = ni()-1, c = ni()-1;
				while(true){
					int nr = end[r][c][0], nc = end[r][c][1];
					if(nr == -999){
						out.println("-1 -1");
						break;
					}else if(nc == -1 || nc == m || nr == -1 || nr == n){
						out.println((nr+1) + " " + (nc+1));
						break;
					}else if(passed[nr]<<~nc<0){
						out.println("-1 -1");
						break;
					}else{
						passed[nr] |= 1<<nc;
						r = nr; c = nc;
					}
				}
				for(int j = 0;j < n;j+=s){
					passed[j] = 0;
					if(j+s-1 < n)passed[j+s-1] = 0;
				}
			}else if(t == 'C'){
				int r = ni()-1, c = ni()-1;
				char x = nc();
				map[r][c] = x;
				analyze(r/s*s, Math.min(r/s*s+s-1, n-1), map, end);
			}
		}
	}
	
	int[] q = new int[100000];
	
	void analyze(int low, int high, char[][] map, int[][][] end)
	{
		int m = map[0].length;
		int[] from = new int[(high-low+3)*(m+2)];
		int[] to = new int[(high-low+3)*(m+2)];
		int p = 0;
		for(int i = low;i <= high;i++){
			for(int j = 0;j < m;j++){
				char c = map[i][j];
				int t = (i-low+1)*(m+2) + j+1;
				if(c == '>'){
					from[p] = t+1; to[p] = t; p++;
				}else if(c == '<'){
					from[p] = t-1; to[p] = t; p++;
				}else if(c == '^'){
					from[p] = t-(m+2); to[p] = t; p++;
				}else if(c == 'v'){
					from[p] = t+(m+2); to[p] = t; p++;
				}
			}
		}
		
		int[][] g = packD((high-low+3)*(m+2), from, to, p);
		int[] ends = new int[(high-low+3)*(m+2)];
		Arrays.fill(ends, -1);
		p = 0;
//		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < m+2;i++){
			q[p++] = 0*(m+2)+i;
			q[p++] = (high-low+2)*(m+2)+i;
		}
		for(int i = 0;i < high-low+3;i++){
			q[p++] = i*(m+2)+0;
			q[p++] = i*(m+2)+m+1;
		}
		for(int i = 0;i < p;i++){
			int x = q[i];
			ends[x] = x;
		}
		for(int r = 0;r < p;r++){
			int cur = q[r];
			for(int e : g[cur]){
				if(ends[e] == -1){
					ends[e] = ends[cur];
					q[p++] = e;
				}
			}
		}
		for(int i = low;i <= high;i++){
			for(int j = 0;j < m;j++){
				int e = ends[(i-low+1)*(m+2)+j+1];
				if(e == -1){
					end[i][j][0] = end[i][j][1] = -999;
				}else{
					end[i][j][0] = e/(m+2)+low-1;
					end[i][j][1] = e%(m+2)-1;
				}
			}
		}
	}
	
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
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