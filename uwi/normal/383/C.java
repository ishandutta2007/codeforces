//package round225;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		int[] w = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = a[from[i]] + a[to[i]];
		}
		int[][][] g = packWU(n, from, to, w);
		int[][] pars = parents(g, 0);
		int[] pw = pars[4];
		int[][] et = eulerTour(g, 0);
		int[] first = et[2];
		int[] dep = pars[2];
		int[] vs = et[0], deps = et[1];
		int[] ft = new int[2*n+1];
		
		int[][] pls = new int[n][2];
		int[] pp = new int[n];
		for(int i = 0;i < vs.length-1;i++){
			if(deps[i] < deps[i+1]){
				addFenwick(ft, i+1, (deps[i+1]&1) == 0 ? pw[vs[i+1]] : -pw[vs[i+1]]);
				pls[vs[i+1]][pp[vs[i+1]]++] = ((deps[i+1]&1) == 0 ? 0 : 1<<22)|i;
			}else{
				addFenwick(ft, i+1, (deps[i]&1) == 0 ? -pw[vs[i]] : pw[vs[i]]);
				pls[vs[i]][pp[vs[i]]++] = ((deps[i]&1) == 0 ? 1<<22 : 0)|i;
			}
		}
		addFenwick(ft, 0, a[0]);
		
		int mask = (1<<22)-1;
		for(int t = 0;t < m;t++){
			int type = ni();
			if(type == 1){
				int x = ni()-1;
				int val = ni();
				if(x == 0){
					addFenwick(ft, 0, val);
				}else{
					for(int i = 0;i < pp[x];i++){
						addFenwick(ft, (pls[x][i]&mask)+1, (pls[x][i]>>>22 == 0 ? val : -val));
					}
				}
			}else{
				int x = ni()-1;
				int u = sumFenwick(ft, first[x]);
				out.println((dep[x]&1) == 0 ? u : -u);
			}
		}
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int[][] eulerTour(int[][][] g, int root)
	{
		int n = g.length;
		int[] vs = new int[2*n-1];
		int[] deps = new int[2*n-1];
		int[] first = new int[n];
		Arrays.fill(first, -1);
		int p = 0;
		
		int[] stack = new int[n];
		int[] inds = new int[n];
		int sp = 0;
		stack[sp++] = root;
		outer:
		while(sp > 0){
			int cur = stack[sp-1], ind = inds[sp-1];
			vs[p] = cur;
			deps[p] = sp-1;
			if(first[cur] == -1)first[cur] = p;
			p++;
			while(ind < g[cur].length){
				int nex = g[cur][ind++][0];
				if(first[nex] == -1){
					inds[sp-1] = ind;
					stack[sp] = nex;
					inds[sp] = 0;
					sp++;
					continue outer;
				}
			}
			inds[sp-1] = ind;
			if(ind == g[cur].length)sp--;
		}
		
		return new int[][]{vs, deps, first};
	}
	
	public static int[][] parents(int[][][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		int[] dw = new int[n];
		int[] pw = new int[n];
		int[] dep = new int[n];
		
		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int[] nex : g[cur]){
				if(par[cur] != nex[0]){
					q[r++] = nex[0];
					par[nex[0]] = cur;
					dep[nex[0]] = dep[cur] + 1;
					dw[nex[0]] = dw[cur] + nex[1];
					pw[nex[0]] = nex[1];
				}
			}
		}
		return new int[][] {par, q, dep, dw, pw};
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
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