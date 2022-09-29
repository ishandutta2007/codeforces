//package round589;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 1 2 1 5 1 6 2 3 2 4";
	String INPUT = "";
	
	void solve()
	{
		int D = ni();
		int n = (1<<D)-2;
		int[] from = new int[n - 1];
		int[] to = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][] g = packU(n, from, to);
		
		if(n >= 3){
			int[] root = new int[2];
			int rootct = 0;
			int gate = -1;
			int gatect = 0;
			for(int i = 0;i < n;i++){
				if(g[i].length == 2){
					if(rootct == 2){
						out.println(0);
						return;
					}
					root[rootct++] = i;
				}
				if(g[i].length == 4){
					gate = i;
					gatect++;
				}
				if(g[i].length > 4){
					out.println(0);
					return;
				}
			}
			if(rootct == 1 || gatect == 1){
				int[][] pars = parents3(g, root[0]);
				int[] par = pars[0], ord = pars[1], dep = pars[2];
				int[] des = new int[n];
				Arrays.fill(des, 1);
				for(int i = n-1;i > 0;i--){
					int cur = ord[i];
					des[par[cur]] += des[cur];
				}
				for(int i = n-1;i >= 0;i--){
					int cur = ord[i];
					if(cur == gate){
						int[] chd = new int[3];
						int p = 0;
						for(int e : g[cur]){
							if(par[cur] == e)continue;
							chd[p++] = des[e];
						}
						assert p == 3;
						Arrays.sort(chd);
						if(chd[0] == chd[1] && chd[2] == 2*chd[1] + 1 && Integer.bitCount(chd[0]+1) == 1){
						}else{
							out.println(0);
							return;
						}
						for(int x = cur;x != root[0];x = par[x]){
							des[x]++;
						}
					}else if(cur == root[0]){
						if(des[g[cur][0]] != des[g[cur][1]]){
							out.println(0);
							return;
						}
					}else if(g[cur].length == 3){
						int[] chd = new int[2];
						int p = 0;
						for(int e : g[cur]){
							if(par[cur] == e)continue;
							chd[p++] = des[e];
						}
						assert p == 2;
						if(chd[0] == chd[1]){
						}else{
							out.println(0);
							return;
						}
					}
				}
				out.println(1);
				out.println(gate+1);
				return;
			}
			if(rootct == 2 && gatect == 0){
				List<Integer> cans = new ArrayList<>();
				if(check(from, to, root[0], n, root[1])){
					cans.add(root[0]);
				}
				if(check(from, to, root[1], n, root[0])){
					cans.add(root[1]);
				}
				Collections.sort(cans);
				out.println(cans.size());
				for(int can : cans){
					out.print(can+1 + " ");
				}
				if(cans.size() > 0)out.println();
				return;
			}
			if(rootct == 0 && gatect == 0){
				List<Integer> cans = new ArrayList<>();
				int[] cents = center2(g);
				for(int cent : cents){
					if(g[cent].length != 3)continue;
					for(int i = 0;i < 8;i++){
						if(Integer.bitCount(i) != 2)continue;
						int[] rem = new int[2];
						int p = 0;
						for(int j = 0;j < 3;j++){
							if(i<<~j<0){
								rem[p++] = g[cent][j];
							}
						}
						if(check(from, to, cent, rem[0], rem[1], n, cent)){
							cans.add(cent);
						}
					}
				}
				Collections.sort(cans);
				out.println(cans.size());
				for(int can : cans){
					out.print(can+1 + " ");
				}
				if(cans.size() > 0)out.println();
				return;
			}
			out.println(0);
		}else{
			out.println(2);
			out.println(1 + " " + 2);
		}
	}
	
	public static int[] center2(int[][] g)
	{
		int n = g.length;
		int[] q = new int[n];
		int[] deg = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			deg[i] = g[i].length;
			if(g[i].length <= 1){ // < for n=1
				q[p++] = i;
			}
		}
		int bound = p == n ? 0 : p;
		for(int z = 0;z < p;z++){
			if(bound == z && p < n)bound = p;
			int cur = q[z];
			deg[cur]--;
			for(int e : g[cur]){
				if(--deg[e] == 1)q[p++] = e;
			}
		}
		assert p == n;
		assert bound >= n-2 && bound < n;
		if(bound == n-2){
			return new int[]{q[n-2], q[n-1]};
		}else{
			return new int[]{q[n-1]};
		}
	}

	
	boolean check(int[] from, int[] to, int ff, int tt, int root)
	{
		int[] lf = Arrays.copyOf(from, from.length+1);
		int[] lt = Arrays.copyOf(to, to.length+1);
		lf[lf.length-1] = ff;
		lt[lt.length-1] = tt;
		int n = lf.length+1;
		int[][] g = packU(n, lf, lt);
		int[][] pars = parents3(g, root);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i > 0;i--){
			int cur = ord[i];
			des[par[cur]] += des[cur];
		}
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			
			if(g[cur].length >= 2){
				int[] chd = new int[2];
				int p = 0;
				for(int e : g[cur]){
					if(par[cur] == e)continue;
					chd[p++] = des[e];
				}
				assert p == 2;
				if(chd[0] == chd[1]){
				}else{
					return false;
				}
			}
		}
		return true;
	}

	boolean check(int[] from, int[] to, int ff, int tt, int tt2, int plus, int root)
	{
		int[] lf = Arrays.copyOf(from, from.length+1);
		int[] lt = Arrays.copyOf(to, to.length+1);
		lf[from.length] = ff;
		lt[from.length] = plus;
		for(int i = 0;i < from.length;i++){
			if(lf[i] == ff && lt[i] == tt){
				lf[i] = plus;
			}
			if(lf[i] == tt && lt[i] == ff){
				lt[i] = plus;
			}
			if(lf[i] == ff && lt[i] == tt2){
				lf[i] = plus;
			}
			if(lf[i] == tt2 && lt[i] == ff){
				lt[i] = plus;
			}
		}
		int n = lf.length+1;
		int[][] g = packU(n, lf, lt);
		int[][] pars = parents3(g, root);
		int[] par = pars[0], ord = pars[1], dep = pars[2];
		int[] des = new int[n];
		Arrays.fill(des, 1);
		for(int i = n-1;i > 0;i--){
			int cur = ord[i];
			des[par[cur]] += des[cur];
		}
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			
			if(g[cur].length >= 2){
				int[] chd = new int[2];
				int p = 0;
				for(int e : g[cur]){
					if(par[cur] == e)continue;
					chd[p++] = des[e];
				}
				assert p == 2;
				if(chd[0] == chd[1]){
				}else{
					return false;
				}
			}
		}
		return true;
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