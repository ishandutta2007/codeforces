//package aim.r4;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[] des = new int[n];
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			des[cur]++;
			if(i > 0)des[par[cur]] += des[cur];
		}
		
		int[] necks = new int[n];
		int[] pseps = new int[n];
		int p = 0;
		
		BitSet seps = new BitSet();
		
		outer:
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				if(par[i] == e){
					if((n-des[i])*2 > n)continue outer;
				}else{
					if(des[e]*2 > n)continue outer;
				}
			}
			seps.set(i);;
			// i is separator
			for(int e : g[i]){
				pseps[p] = i;
				necks[p++] = e;
			}
		}
		
		for(int i = 0;i < p;i++){
			if(seps.get(necks[i]))continue;
			Deque<Integer> dq = dfsStraight(necks[i], pseps[i], g);
			dfsFold(dq, pseps[i]);
		}
		
		out.println(ans.size());
		for(int[] u : ans){
			for(int k = 0;k < 3;k++){
				out.print(u[k]+1 + " ");
			}
			out.println();
		}
		return;
	}
	
	List<int[]> ans = new ArrayList<>();
	
	void dfsFold(Deque<Integer> d, int psep)
	{
		d.addFirst(psep);
		if(d.size() < 2)return;
		int l1 = d.pollLast();
		int l2 = d.pollLast();
		while(!d.isEmpty()){
			int l3 = d.pollLast();
//			tr("fold", l3, l2, l1);
			ans.add(new int[]{l3, l2, l1});
			l2 = l3;
		}
	}
	
	Deque<Integer> dfsStraight(int neck, int psep, int[][] g)
	{
//		tr(neck, psep);
		Deque<Integer> ret = new ArrayDeque<>();
		
		List<Deque<Integer>> dqs = new ArrayList<>();
		Deque<Integer> longest = new ArrayDeque<>();
		for(int e : g[neck]){
			if(e == psep)continue;
			Deque<Integer> res = dfsStraight(e, neck, g);
			dqs.add(res);
			if(res.size() > longest.size())longest = res;
		}
		
		int p = psep;
		for(Deque<Integer> res : dqs){
			if(res == longest)continue;
			int last = res.peekLast();
			while(!res.isEmpty()){
				ret.addLast(res.pollLast());
			}
//			tr("straight", p, neck, last);
			ans.add(new int[]{p, neck, last});
			p = ret.peekLast();
		}
		ret.addLast(neck);
		while(!ret.isEmpty()){
			longest.addFirst(ret.pollLast());
		}
		return longest;
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }


	public static int[] buildCentroidTree(int[][] g) {
		int n = g.length;
		int[] ctpar = new int[n];
		Arrays.fill(ctpar, -1);
		buildCentroidTree(g, 0, new boolean[n], new int[n], new int[n], new int[n], ctpar);
		return ctpar;
	}
	
	private static int buildCentroidTree(int[][] g, int root, boolean[] sed, int[] par, int[] ord, int[] des, int[] ctpar)
	{
		// parent and level-order
		ord[0] = root;
		par[root] = -1;
		int r = 1;
		for(int p = 0;p < r;p++) {
			int cur = ord[p];
			for(int nex : g[cur]){
				if(par[cur] != nex && !sed[nex]){
					ord[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		// if(r == 1)return;
		
		// DP and find a separator
		int sep = -1; // always exists
		outer:
		for(int i = r-1;i >= 0;i--){
			int cur = ord[i];
			des[cur] = 1;
			for(int e : g[cur]){
				if(par[cur] != e && !sed[e])des[cur] += des[e];
			}
			if(r-des[cur] <= r/2){
				for(int e : g[cur]){
					if(par[cur] != e && !sed[e] && des[e] >= r/2+1)continue outer;
				}
				sep = cur;
				break;
			}
		}
		
		sed[sep] = true;
		for(int e : g[sep]){
			if(!sed[e])ctpar[buildCentroidTree(g, e, sed, par, ord, des, ctpar)] = sep;
		}
		return sep;
	}
	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}

	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
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
	
	public static void main(String[] args) throws Exception { new C3().run(); }
	
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