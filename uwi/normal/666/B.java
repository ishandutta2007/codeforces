//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class B666_2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(),  m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		int[][] ig = packD(n, to, from);
		int[][] ds = new int[n][];
		int[][] ids = new int[n][];
		for(int i = 0;i < n;i++){
			ds[i] = dist(g, i);
			ids[i] = dist(ig, i);
		}
		long[] temp = new long[n];
		long[][] dsi = new long[n][];
		int Z = 100000;
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = 0;j < n;j++){
				if(ds[i][j] < Integer.MAX_VALUE / 2){
					temp[p++] = (long)(Z-ds[i][j])<<32|j;
				}
			}
			Arrays.sort(temp, 0, p);
			dsi[i] = Arrays.copyOf(temp, p);
		}
		long[][] idsi = new long[n][];
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = 0;j < n;j++){
				if(ids[i][j] < Integer.MAX_VALUE / 2){
					temp[p++] = (long)(Z-ids[i][j])<<32|j;
				}
			}
			Arrays.sort(temp, 0, p);
			idsi[i] = Arrays.copyOf(temp, p);
		}
		
		int max = -1;
		int[] arg = null;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i == j)continue;
				if(ds[i][j] >= Integer.MAX_VALUE / 2)continue;
				int a1 = -1, a2 = -1;
				int b1 = -1, b2 = -1;
				for(long k : idsi[i]){
					int ind = (int)k;
					if(ind != i && ind != j){
						if(a1 == -1){
							a1 = ind;
						}else if(a2 == -1){
							a2 = ind;
							break;
						}
					}
				}
				for(long l : dsi[j]){
					int ind = (int)l;
					if(ind != i && ind != j){
						if(b1 == -1){
							b1 = ind;
						}else if(b2 == -1){
							b2 = ind;
							break;
						}
					}
				}
				if(a1 != -1 && b1 != -1 && a1 != b1){
					int d = ds[a1][i] + ds[i][j] + ds[j][b1];
					if(d > max){
						max = d;
						arg = new int[]{a1, i, j, b1};
					}
				}
				if(a1 != -1 && b2 != -1 && a1 != b2){
					int d = ds[a1][i] + ds[i][j] + ds[j][b2];
					if(d > max){
						max = d;
						arg = new int[]{a1, i, j, b2};
					}
				}
				if(a2 != -1 && b1 != -1 && a2 != b1){
					int d = ds[a2][i] + ds[i][j] + ds[j][b1];
					if(d > max){
						max = d;
						arg = new int[]{a2, i, j, b1};
					}
				}
			}
		}
		out.println(
				(arg[0]+1) + " " +
						(arg[1]+1) + " " +
						(arg[2]+1) + " " +
						(arg[3]+1));
	}
	
	int[] dist(int[][] g, int s)
	{
		Queue<Integer> q = new ArrayDeque<>();
		q.add(s);
		int n = g.length;
		int[] d = new int[n];
		Arrays.fill(d, Integer.MAX_VALUE / 2);
		d[s] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(d[e] > d[cur] + 1){
					d[e] = d[cur] + 1;
					q.add(e);
				}
			}
		}
		return d;
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
	
	public static void main(String[] args) throws Exception { new B666_2().run(); }
	
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