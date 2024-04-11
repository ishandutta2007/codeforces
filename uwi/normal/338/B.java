//package round196;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] a = na(m);
		boolean[] pa = new boolean[n];
		for(int v : a)pa[v-1] = true;
		
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents(g, 0);
		int[] par = pars[0], ord = pars[1];
		int[] farl = new int[n];
		int[] farl2 = new int[n];
		Arrays.fill(farl, -1);
		Arrays.fill(farl2, -1);
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			int[] fs = new int[g[cur].length+1];
			int fp = 0;
			if(pa[cur]){
				fs[fp++] = 0;
			}
			for(int e : g[cur]){
				if(par[cur] != e){
					if(farl[e] != -1){
						fs[fp++] = farl[e] + 1;
					}
				}
			}
			Arrays.sort(fs, 0, fp);
			if(fp > 0){
				farl[cur] = fs[fp-1];
			}
			if(fp-1 > 0){
				farl2[cur] = fs[fp-2];
			}
		}
		int[] faru = new int[n];
		Arrays.fill(faru, -1);
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			if(i > 0){
				if(faru[par[cur]] != -1){
					faru[cur] = Math.max(faru[cur], faru[par[cur]] + 1);
				}
				if(farl[cur] != -1 && farl[par[cur]] == farl[cur] + 1){
					if(farl2[par[cur]] != -1){
						faru[cur] = Math.max(faru[cur], farl2[par[cur]] + 1);
					}
				}else{
					if(farl[par[cur]] != -1){
						faru[cur] = Math.max(faru[cur], farl[par[cur]] + 1);
					}
				}
			}
		}
		int ct = 0;
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			int x = Math.max(faru[cur], farl[cur]);
			if(x <= K && x >= 0)ct++;
		}
		out.println(ct);
	}
	
	public static int[][] parents(int[][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		return new int[][] {par, q};
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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