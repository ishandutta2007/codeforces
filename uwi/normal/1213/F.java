//package round582;
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
		int n = ni(), K = ni();
		int[] P = na(n);
		int[] Q = na(n);
		int[] from = new int[2*(n-1)];
		int[] to = new int[2*(n-1)];
		int p = 0;
		for(int i = 0;i < n-1;i++){
			from[p] = P[i]-1;
			to[p] = P[i+1]-1;
			p++;
			from[p] = Q[i]-1;
			to[p] = Q[i+1]-1;
			p++;
		}
		int[][] g = packD(n, from, to);
		int[] clus = decomposeToSCCNoRec(g);
		int max = 0;
		for(int c : clus){
			max = Math.max(max, c);
		}
		if(max+1 >= K){
			out.println("YES");
			for(int i = 0;i < n;i++){
				out.print((char)('a'+Math.min(max-clus[i], 25)));
			}
			out.println();
		}else{
			out.println("NO");
		}
	}
	
	
	public static int[] decomposeToSCCNoRec(int[][] g)
	{
		int n = g.length;
		int[] stack = new int[n+1];
		int[] ind = new int[n+1];
		int[] ord = new int[n];
		Arrays.fill(ord, -1);
		int[] low = new int[n];
		Arrays.fill(low, -1);
		int sp = 0;
		int id = 0; // preorder
		int[] clus = new int[n];
		int cid = 0;
		int[] cstack = new int[n+1];
		int csp = 0;
		boolean[] incstack = new boolean[n];
		for(int i = 0;i < n;i++){
			if(ord[i] == -1){
				ind[sp] = 0;
				cstack[csp++] = i;
				stack[sp++] = i;
				incstack[i] = true;
				while(sp > 0){
					int cur = stack[sp-1];
					if(ind[sp-1] == 0){
						ord[cur] = low[cur] = id++;
					}
					if(ind[sp-1] < g[cur].length){
						int nex = g[cur][ind[sp-1]];
						if(ord[nex] == -1){
							ind[sp-1]++;
							ind[sp] = 0;
							incstack[nex] = true;
							cstack[csp++] = nex;
							stack[sp++] = nex;
						}else{
							// shortcut
//							U.tr(cur, nex, incstack[nex], low[nex], stack);
							if(incstack[nex])low[cur] = Math.min(low[cur], ord[nex]); // low is ok too, but slower.
							ind[sp-1]++;
						}
					}else{
						if(ord[cur] == low[cur]){
							while(csp > 0){
								incstack[cstack[csp-1]] = false;
								clus[cstack[--csp]] = cid;
								if(cstack[csp] == cur)break;
							}
							cid++;
						}
						if(--sp >= 1)low[stack[sp-1]] = Math.min(low[stack[sp-1]], low[stack[sp]]);
					}
				}
			}
		}
		return clus;
	}
	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
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