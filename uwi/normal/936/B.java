//package round467;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = na(ni());
			for(int j = 0;j < g[i].length;j++){
				g[i][j]--;
			}
		}
		int S = ni()-1;
		
		int[][] d = new int[2][n];
		int I = 9999999;
		int[][] prev = new int[2][n];
		Arrays.fill(d[0], I);
		Arrays.fill(d[1], I);
		Arrays.fill(prev[0], -1);
		Arrays.fill(prev[1], -1);
		d[0][S] = 0;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(S<<1|0);
		while(!q.isEmpty()){
			int cur = q.poll();
			int pa = cur&1;
			cur >>>= 1;
			for(int e : g[cur]){
				if(d[pa^1][e] > d[pa][cur] + 1){
					d[pa^1][e] = d[pa][cur] + 1;
					prev[pa^1][e] = cur;
					q.add(e<<1|(pa^1));
				}
			}
		}
		
		int mind = I;
		int arg = -1;
		for(int i = 0;i < n;i++){
			if(g[i].length == 0 && d[1][i] < I){
				if(d[1][i] < mind){
					mind = d[1][i];
					arg = i;
				}
			}
		}
		if(arg != -1){
			int i = arg;
			int[] route = new int[d[1][i]+1];
			int cur = i;
			int pa = 1;
			int ld = d[1][i];
			
			while(ld >= 0){
				route[ld] = cur;
				cur = prev[pa][cur];
				pa ^= 1;
				ld--;
			}
			out.println("Win");
			for(int j = 0;j <= d[1][i];j++){
				out.print((route[j]+1) + " ");
			}
			return;
		}
		
		int[] clus = decomposeToSCC(g);
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				if(d[0][i] < I && d[1][e] < I &&
						clus[i] == clus[e]){
					out.println("Draw");
					return;
				}
				if(d[1][i] < I && d[0][e] < I &&
						clus[i] == clus[e]){
					out.println("Draw");
					return;
				}
			}
		}
		out.println("Lose");
	}
	
	public static int[] decomposeToSCC(int[][] g)
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
							if(incstack[nex])low[cur] = Math.min(low[cur], low[nex]);
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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