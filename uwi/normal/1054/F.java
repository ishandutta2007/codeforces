//package mailru2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] xs = new int[n];
		int[] ys = new int[n];
		
		for(int i = 0;i < n;i++){
			xs[i] = ni();
			ys[i] = ni();
		}
		
		int[] ix = shrinkX(xs);
		int[] iy = shrinkX(ys);
		
		int N = ix.length;
		int M = iy.length;
		boolean[][] con = new boolean[N][M];
		for(int i = 0;i < n;i++){
			con[xs[i]][ys[i]] = true;
		}
		
		int rgen = -1;
		int[][] rid = new int[N][M];
		{
			for(int i = 0;i < N;i++){
				int first = -1, last = -1;
				for(int j = 0;j < M;j++){
					if(con[i][j]){
						if(first == -1)first = j;
						last = j;
					}
				}
				Arrays.fill(rid[i], -1);
				for(int j = first;j <= last;j++){
					if(!con[i][j]){
						if(con[i][j-1]){
							rgen++;
						}
						rid[i][j] = rgen;
					}
				}
			}
		}
		int cgen = -1;
		int[][] cid = new int[N][M];
		{
			for(int i = 0;i < N;i++)Arrays.fill(cid[i], -1);
			for(int i = 0;i < M;i++){
				int first = -1, last = -1;
				for(int j = 0;j < N;j++){
					if(con[j][i]){
						if(first == -1)first = j;
						last = j;
					}
				}
				for(int j = first;j <= last;j++){
					if(!con[j][i]){
						if(con[j-1][i]){
							cgen++;
						}
						cid[j][i] = cgen;
					}
				}
			}
		}
		
		rgen++; cgen++;
		
		int[] from = new int[N*M];
		int[] to = new int[N*M];
		int p = 0;
		boolean[][] gb = new boolean[rgen][cgen];
		for(int i = 0;i < N;i++){
			for(int j = 0;j < M;j++){
				if(rid[i][j] >= 0 && cid[i][j] >= 0){
					from[p] = rid[i][j];
					to[p] = cid[i][j];
					gb[from[p]][to[p]] = true;
					p++;
				}
			}
		}
		int[][] g = packD(rgen, from, to, p);
		
		int[] mat = doBipartiteMatchingHK(g, cgen);
		
		boolean[] z = mincover(gb, mat);
		// minimum vertex cover = (L and not Z) or (R and Z)
		// MIS = (L and Z) or (R and not Z)
		List<String> rows = new ArrayList<>();
		for(int i = 0;i < N;i++){
			for(int j = 0;j < M;j++){
				if(con[i][j]){
					int k = j+1;
					for(;k < M && (con[i][k] || rid[i][k] != -1 && !z[rid[i][k]]);k++);
					rows.add(ix[i] + " " + iy[j] + " " + ix[i] + " " + iy[k-1]);
					j = k-1;
				}
			}
		}
		
		List<String> cols = new ArrayList<>();
		for(int i = 0;i < M;i++){
			for(int j = 0;j < N;j++){
				if(con[j][i]){
					int k = j+1;
					for(;k < N && (con[k][i] || cid[k][i] != -1 && !z[cid[k][i]+rgen]);k++);
					cols.add(ix[j] + " " + iy[i] + " " + ix[k-1] + " " + iy[i]);
					j = k-1;
				}
			}
		}
		
		out.println(cols.size());
		for(String line : cols)out.println(line);
		out.println(rows.size());
		for(String line : rows)out.println(line);
	}
	
	public static boolean[] mincover(boolean[][] g, int[] mat)
	{
		if(g.length == 0)return null;
		int n = g.length, m = g[0].length;
		boolean[] z = new boolean[n+m];
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < n;i++){
			if(mat[i] == -1){
				z[i] = true;
				q.add(i);
			}
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			if(cur < n){
				for(int i = 0;i < m;i++){
					if(g[cur][i] && mat[cur] != i && !z[i+n]){
						z[i+n] = true;
						q.add(i+n);
					}
				}
			}else{
				for(int i = 0;i < n;i++){
					if(mat[i] == cur-n && !z[i]){
						z[i] = true;
						q.add(i);
						break;
					}
				}
			}
		}
		
		// minimum vertex cover = (L and not Z) or (R and Z)
		for(int i = 0;i < n;i++)z[i] ^= true;
		return z;
	}
	
	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}

	public static int[] doBipartiteMatchingHK(int[][] g, int m)
	{
		int n = g.length;
		if(n == 0)return new int[0];
		int[] from = new int[m];
		int[] to = new int[n];
		Arrays.fill(to, -1);
		Arrays.fill(from, n);
		
		int[] d = new int[n+1];
		int mat = 0;
		while(true){
			Arrays.fill(d, -1);
			int[] q = new int[n];
			int r = 0;
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					d[i] = 0;
					q[r++] = i;
				}
			}
			
			for(int p = 0;p < r;p++) {
				int cur = q[p];
				for(int adj : g[cur]){
					int nex = from[adj];
					if(d[nex] == -1) {
						if(nex != n)q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
			}
			if(d[n] == -1)break;
			
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					if(dfsHK(d, g, n, m, to, from, i))mat++;
				}
			}
		}
		
		return to;
	}
	
	static boolean dfsHK(int[] d, int[][] g, int n, int m, int[] to, int[] from, int cur)
	{
		if(cur == n)return true;
		for(int adj : g[cur]){
			int nex = from[adj];
			if(d[nex] == d[cur] + 1 && dfsHK(d, g, n, m, to, from, nex)){
				to[cur] = adj;
				from[adj] = cur;
				return true;
			}
		}
		d[cur] = -1;
		return false;
	}
	
	public static int[] shrinkX(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int) (b[0] >> 32);
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0) {
				p++;
				ret[p] = (int) (b[i] >> 32);
			}
			a[(int) b[i]] = p;
		}
		return Arrays.copyOf(ret, p + 1);
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