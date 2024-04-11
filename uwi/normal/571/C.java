//package round317;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] f = new int[m+1][2];
		for(int i = 0;i < m+1;i++){
			f[i][0] = f[i][1] = -1;
		}
		int[] fp = new int[m+1];
		int[] ptn = new int[m+1];
		
//		int[][] gg = new int[n][];
		for(int i = 0;i < n;i++){
			int L = ni();
//			int[] row = new int[L];
//			gg[i] = row;
			for(int j = 0;j < L;j++){
				int x = ni();
//				row[j] = x;
				int id = Math.abs(x);
				f[id][fp[id]++] = i;
				if(fp[id] == 2 && x > 0){
					int u = f[id][0]; f[id][0] = f[id][1]; f[id][1] = u;
				}
				if(x > 0){
					ptn[id] |= 1;
				}else{
					ptn[id] |= 2;
				}
			}
		}
		
		DJSet ds = new DJSet(n);
		boolean[] trigger = new boolean[m+1];
		for(int i = 1;i <= m;i++){
			if(ptn[i] != 3){
				for(int j = 0;j < fp[i];j++){
					ds.ex[ds.root(f[i][j])] = true;
				}
			}else{
				if(ds.union(f[i][0], f[i][1])){
					trigger[i] = true;
					ds.ex[ds.root(f[i][0])] = true;
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				if(!ds.ex[i]){
					out.println("NO");
					return;
				}
			}
		}
		
		out.println("YES");
		
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m]; // id
		int p = 0;
		for(int i = 1;i <= m;i++){
			if(ptn[i] == 3){
				from[p] = f[i][0]; to[p] = f[i][1]; w[p] = i; p++;
			}
		}
		int[][][] g = packWU(n, from, to, w, p);
		
		char[] ret = new char[m+1];
		Arrays.fill(ret, '.');
		int[] val = new int[n];
//		Q q = new Q(4*n+4*m+10);
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 1;i <= m;i++){
			if(ptn[i] == 0){
				ret[i] = '1';
			}else if(ptn[i] == 1){
				for(int j = 0;j < fp[i];j++){
					if(val[f[i][j]] == 0)q.add(f[i][j]);
					val[f[i][j]] = 1;
				}
				ret[i] = '1';
			}else if(ptn[i] == 2){
				for(int j = 0;j < fp[i];j++){
					if(val[f[i][j]] == 0)q.add(f[i][j]);
					val[f[i][j]] = 1;
				}
				ret[i] = '0';
			}else if(trigger[i]){
				if(val[f[i][0]] == 0)q.add(f[i][0]);
				val[f[i][0]] = 1;
				ret[i] = '1';
			}
		}
		
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int[] e : g[cur]){
				if(val[e[0]] == 1)continue;
				int id = e[1];
				if(ret[id] != '.')continue;
				if(e[0] == f[id][0]){
					ret[id] = '1';
				}else{
					ret[id] = '0';
				}
				val[e[0]] = 1;
				q.add(e[0]);
			}
		}
		for(int i = 1;i <= m;i++){
			if(ret[i] == '.'){
				ret[i] = '1';
			}
		}
		out.println((new String(ret)).substring(1));
		
		// verify
//		tr(new String(ret));
//		inner:
//		for(int i = 0;i < n;i++){
//			for(int v : gg[i]){
//				if(v > 0){
//					if(ret[v] == '1')continue inner;
//				}else{
//					if(ret[-v] == '0')continue inner;
//				}
//			}
//			throw new RuntimeException("DEAD " + i);
//		}
	}
	
	public static class Q {
		public int[] q;
		protected int pt, ph;
		public Q(int n){ q = new int[n]; pt = ph = 0; }
		public void add(int x){ q[ph++] = x; }
		public void clear(){ pt = ph = 0; }
		public int poll(){ return q[pt++]; }
		public int size(){ return ph-pt; }
		public boolean isEmpty(){ return ph==pt; }
	}

	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	public static class DJSet {
		public int[] upper;
		public boolean[] ex;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
			ex = new boolean[n];
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
				ex[x] |= ex[y];
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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