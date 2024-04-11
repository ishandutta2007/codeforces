//package round619;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++) {
			a[i] = na(m);
			for(int j = 0;j < m;j++)a[i][j]--;
		}
		
		int[][] b = new int[K][n*m];
		int[] bp = new int[K];
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				b[a[i][j]][bp[a[i][j]]++] = i*m+j;
			}
		}
		for(int i = 0;i < K;i++)b[i] = Arrays.copyOf(b[i], bp[i]);
		
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int[][] dss = new int[K][];
		DQ q = new DQ(10005000);
		for(int k = 0;k < K;k++) {
			int[] ds = new int[n*m+K];
//			Deque<Integer> q = new ArrayDeque<>();
			q.clear();
			q.addLast(n*m+k);
			Arrays.fill(ds, 99999999);
			ds[n*m+k] = 0;
			while(!q.isEmpty()) {
				int cur = q.pollFirst();
				if(cur >= n*m) {
					int id = cur-n*m;
					for(int j = 0;j < bp[id];j++) {
						int to = b[id][j];
//						int nr = to / m, nc = to % m;
						if(ds[to] > ds[cur] + 1) {
							ds[to] = ds[cur] + 1;
							q.addLast(to);
						}
					}
				}else {
					int r = cur/m, c = cur-r*m;
					for(int u = 0;u < 4;u++) {
						int nr = r + dr[u], nc = c + dc[u];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m && ds[nr*m+nc] > ds[cur] + 1) {
							ds[nr*m+nc] = ds[cur] + 1;
							q.addLast(nr*m+nc);
						}
					}
					int to = n*m+a[r][c];
					if(ds[to] > ds[cur]) {
						ds[to] = ds[cur];
						q.addFirst(to);
					}
				}
			}
			dss[k] = ds;
		}
		
		for(int Q = ni();Q > 0;Q--) {
			int r1 = ni()-1, c1 = ni()-1, r2 = ni()-1, c2 = ni()-1;
			int ans = Math.abs(r1-r2) + Math.abs(c1-c2);
			for(int k = 0;k < K;k++) {
				ans = Math.min(ans, dss[k][r2*m+c2] + dss[k][r1*m+c1] - 1);
			}
			out.println(ans);
		}
	}
	
	public static class DQ {
		public int[] q;
		public int n;
		protected int pt, ph;
		
		public DQ(int n){ this.n = Integer.highestOneBit(n)<<1; q = new int[this.n]; pt = ph = 0; }
		
		public void addLast(int x){ q[ph] = x; ph = ph+1&n-1; }
		public void addFirst(int x){ pt = pt+n-1&n-1; q[pt] = x; }
		public int pollFirst(){ int ret = q[pt]; pt = pt+1&n-1; return ret; }
		public int pollLast(){ ph = ph+n-1&n-1; int ret = q[ph]; return ret; }
		public int getFirst(){ return q[pt]; }
		public int getFirst(int k){ return q[pt+k&n-1]; }
		public int getLast(){ return q[ph+n-1&n-1]; }
		public int getLast(int k){ return q[ph+n-k-1&n-1]; }
		public void clear(){ pt = ph = 0; }
		public int size(){ return ph-pt+n&n-1; }
		public boolean isEmpty(){ return ph==pt; }
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