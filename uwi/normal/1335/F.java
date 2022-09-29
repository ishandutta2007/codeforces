//package round634;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}
	
	void go()
	{
		int n = ni(), m = ni();
		char[][] wb = nm(n,m);
		char[][] map = nm(n,m);
		int[] f = new int[n*m];
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		String D = "DRUL";
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				int k = D.indexOf(map[i][j]);
				int ne = i*m+j + dr[k] * m + dc[k];
				f[i*m+j] = ne;
			}
		}
		
		SplitResult res = split(f);
		DJSet ds = new DJSet(n*m);
		for(int i = 0;i < n*m;i++)ds.union(i, f[i]);
		boolean[] done = new boolean[n*m];
		List<Integer> periods = new ArrayList<>();
		
		boolean[] black = new boolean[n*m];
		int[] bases = new int[n*m];
		int[] ps = new int[n*m];
		
		int cc = 0;
		for(int i = 0;i < n*m;i++) {
			if(res.incycle[i]) {
				cc++;
			}
		}
		out.print(cc + " ");
		int[] dp = new int[n*m];
		int base = 0;
		for(int i = n*m-1;i >= 0;i--) {
			int cur = res.ord[i];
			int root = ds.root(cur);
			if(!done[root]) {
				int period = 1;
				for(int x = f[cur];x != cur;x = f[x]) {
					period++;
				}
				periods.add(period);
				done[root] = true;
				bases[cur] = base;
				ps[cur] = period;
				dp[cur] = base;
				base += period;
			}else {
				bases[cur] = bases[f[cur]];
				ps[cur] = ps[f[cur]];
				dp[cur] = dp[f[cur]]+1;
				if(dp[cur] == bases[cur] + ps[cur]) {
					dp[cur] = bases[cur];
				}
			}
			if(wb[cur/m][cur%m] == '0') {
				black[dp[cur]] = true;
			}
		}
//		tr(dp);
//		tr(bases);
//		tr(ps);
		int ans = 0;
		
		for(boolean b : black) {
			if(b)ans++;
		}
		out.println(ans);
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

	
	public static class SplitResult
	{
		public boolean[] incycle;
		public int[] ord;
	}
	
	public static SplitResult split(int[] f)
	{
		int n = f.length;
		boolean[] incycle = new boolean[n];
		Arrays.fill(incycle, true);
		int[] indeg = new int[n];
		for(int i = 0;i < n;i++)indeg[f[i]]++;
		int[] q = new int[n];
		int qp = 0;
		for(int i = 0;i < n;i++){
			if(indeg[i] == 0)q[qp++] = i;
		}
		for(int r = 0;r < qp;r++){
			int cur = q[r];
			indeg[cur] = -9999999;
			incycle[cur] = false;
			int e = f[cur];
			indeg[e]--;
			if(indeg[e] == 0)q[qp++] = e;
		}
		for(int i = 0;i < n;i++){
			if(indeg[i] == 1){
				q[qp++] = i;
				indeg[i] = 0;
				for(int j = f[i];j != i;j = f[j]) {
					q[qp++] = j;
					indeg[j] = 0;
				}
			}
		}
		assert qp == n;
		SplitResult ret = new SplitResult();
		ret.incycle = incycle;
		ret.ord = q;
		return ret;
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