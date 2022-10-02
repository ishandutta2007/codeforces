//package round327;
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
		char[][] map = nm(n,m);
		int[][][] dmap = new int[3][n][m];
		for(int i = 0;i < 3;i++){
			dmap[i] = distMap(map, (char)(i+'1'));
		}
		int I = 999999999;
		long min = Long.MAX_VALUE;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.' && dmap[0][i][j] < I && dmap[1][i][j] < I && dmap[2][i][j] < I){
					min = Math.min(min, dmap[0][i][j] + dmap[1][i][j] + dmap[2][i][j] - 3 + 1);
				}
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		long[][] ds = new long[3][3];
		for(char f = '1';f <= '3';f++){
			for(char t = (char)(f+1);t <= '3';t++){
				long ld = Long.MAX_VALUE;
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						if(map[i][j] == t){
							for(int k = 0;k < 4;k++){
								int nr = i + dr[k], nc = j + dc[k];
								if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
										(map[nr][nc] == '.' || map[nr][nc] == f) &&
										dmap[f-'1'][nr][nc] < I
										){
									ld = Math.min(ld, dmap[f-'1'][nr][nc]);
								}
							}
						}
					}
				}
				ds[f-'1'][t-'1'] = ld;
				ds[t-'1'][f-'1'] = ld;
			}
		}
		if(ds[0][1] < Long.MAX_VALUE && ds[1][2] < Long.MAX_VALUE){
			min = Math.min(min, ds[0][1] + ds[1][2]);
		}
		if(ds[0][1] < Long.MAX_VALUE && ds[2][0] < Long.MAX_VALUE){
			min = Math.min(min, ds[0][1] + ds[2][0]);
		}
		if(ds[1][2] < Long.MAX_VALUE && ds[2][0] < Long.MAX_VALUE){
			min = Math.min(min, ds[1][2] + ds[2][0]);
		}
		
		if(min == Long.MAX_VALUE){
			out.println(-1);
		}else{
			out.println(min);
		}
	}
	
	public static int[][] distMap(char[][] map, char sc)
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int n = map.length;
		if(n == 0)return new int[0][0];
		int m = map[0].length;
		int l = dr.length;
		int[][] d = new int[n][m];
		int I = 999999999;
		for(int i = 0;i < n;i++) {
			Arrays.fill(d[i], 999999999);
		}
		
		int B = Integer.numberOfTrailingZeros(Integer.highestOneBit(m))+1;
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == sc){
					q.add(i<<B|j);
					d[i][j] = 0;
				}
			}
		}
		
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>B, c = cur&(1<<B)-1;
			for(int k = 0;k < l;k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.' && d[nr][nc] == I) { // fix
					d[nr][nc] = d[r][c] + 1;
					q.add(nr<<B|nc);
				}
			}
		}
		return d;
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