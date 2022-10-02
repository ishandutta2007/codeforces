//package round346;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Queue;


public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long K = nl();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		DJSet ds = new DJSet(n*m);
		int[][] es = new int[n*m][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				es[p++] = new int[]{a[i][j], i, j};
			}
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int z = 0;z < es.length;){
			int y = z;
			while(y < es.length && es[y][0] == es[z][0])y++;
			
			for(int u = z;u < y;u++){
				int[] e = es[u];
				int r = e[1], c = e[2];
				for(int k = 0;k < 4;k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] >= a[r][c]){
						ds.union(r*m+c, nr*m+nc);
					}
				}
			}
			
			for(int u = z;u < y;u++){
				int[] e = es[u];
				int r = e[1], c = e[2];
				int sz = -ds.upper[ds.root(r*m+c)];
				if(K % a[r][c] == 0 && K/a[r][c] <= sz){
					Queue<int[]> q = new ArrayDeque<int[]>();
					long rem = K/a[r][c];
					q.add(new int[]{r, c});
					int[][] ret = new int[n][m];
					ret[r][c] = a[r][c];
					rem--;
					while(!q.isEmpty() && rem > 0){
						int[] cur = q.poll();
						for(int k = 0;k < 4;k++){
							int nr = cur[0] + dr[k], nc = cur[1] + dc[k];
							if(nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] >= a[r][c] && ret[nr][nc] == 0 && rem > 0){
								ret[nr][nc] = a[r][c];
								rem--;
								q.add(new int[]{nr, nc});
							}
						}
					}
					if(rem != 0)throw new AssertionError();
					out.println("YES");
					for(int i = 0;i < n;i++){
						for(int j = 0;j < m;j++){
							out.print(ret[i][j] + " ");
						}
						out.println();
					}
					return;
				}
			}
			
			z = y;
		}
		out.println("NO");
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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