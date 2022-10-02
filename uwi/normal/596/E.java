//package round331;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		char[][] map = nm(n,m);
		int t = 10;
		int[][] d = new int[t][];
		for(int i = 0;i < t;i++){
			d[i] = na(2);
		}
		int[] f = new int[n*m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int id = map[i][j]-'0';
				int ni = i + d[id][0];
				int nj = j + d[id][1];
				if(ni >= 0 && ni < n && nj >= 0 && nj < m){
					f[i*m+j] = ni*m+nj;
				}else{
					f[i*m+j] = i*m+j;
				}
			}
		}
		ResultCluster rc = cluster(f);
		int nc = rc.rings.length;
		int[] ptn = new int[nc];
		boolean[] inring = new boolean[n*m];
		for(int i = 0;i < nc;i++){
			for(int e : rc.rings[i]){
				ptn[i] |= 1<<map[e/m][e%m]-'0';
				inring[e] = true;
			}
		}
		int[] ord = sortTopologicallyWithoutCycles(f);
		
		outer:
		for(int i = 0;i < Q;i++){
			char[] s = ns().toCharArray();
			int len = s.length;
			int[] sptn = new int[len+1];
			for(int j = len-1;j >= 0;j--){
				sptn[j] = sptn[j+1] | 1<<s[j]-'0';
			}
			for(int j = 0;j < nc;j++){
				if((sptn[0]&ptn[j]) == sptn[0]){
					out.println("YES");
					continue outer;
				}
			}
			
			int[] dp = new int[n*m];
			for(int j : ord){
				if(s[dp[j]] == map[j/m][j%m]){
					dp[j]++;
				}
				dp[f[j]] = Math.max(dp[f[j]], dp[j]);
				if(dp[j] >= len){
					out.println("YES");
					continue outer;
				}
				if(inring[f[j]] && (sptn[dp[j]]&ptn[rc.clus[f[j]]]) == sptn[dp[j]]){
					out.println("YES");
					continue outer;
				}
			}
			out.println("NO");
		}
	}
	
	static int[] sortTopologicallyWithoutCycles(int[] f)
	{
		int n = f.length;
		int[] indeg = new int[n];
		for(int i = 0;i < n;i++)if(f[i] != -1)indeg[f[i]]++;
		
		boolean[] ved = new boolean[n];
		int[] q = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(indeg[i] == 0){
				ved[i] = true;
				q[p++] = i;
			}
		}
		for(int r = 0;r < p;r++){
			int cur = q[r];
			if(f[cur] != -1 && --indeg[f[cur]] == 0)q[p++] = f[cur];
		}
		return Arrays.copyOf(q, p);
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
		
		int[][] rings = new int[p][];
		int[] temp = new int[n+1];
		for(int i = 0;i < p;i++){
			temp[0] = red[i];
			int j = 1;
			for(;;j++){
				temp[j] = f[temp[j-1]];
				if(temp[j] == temp[0])break;
			}
			rings[clus[red[i]]] = Arrays.copyOf(temp, j);
		}
		ResultCluster rc = new ResultCluster();
		rc.clus = clus;
		rc.rings = rings;
		return rc;
	}
	
	public static class ResultCluster {
		int[] clus;
		int[][] rings;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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