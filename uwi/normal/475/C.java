//package bayan2014.warmup;
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
		char[][] map = nm(n,m);
		int sr = -1, sc = -1;
		out:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'X'){
					sr = i; sc = j;
					break out;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'X' && (i < sr || j < sc)){
					out.println(-1);
					return;
				}
			}
		}
		int[][] cum = new int[n+1][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j] + (map[i][j] == 'X' ? 1 : 0);
			}
		}
		
		
		int rr = 0, rc = 0;
		for(rr = sr;rr < n && map[rr][sc] == 'X';rr++);
		for(rc = sc;rc < m && map[sr][rc] == 'X';rc++);
		int min = Integer.MAX_VALUE;
		for(int k = 1;k <= rc-sc;k++){
			if(simulate(sr, sc, rr-sr, k, map, cum, n, m)){
				min = Math.min(min, (rr-sr)*k);
			}
		}
		for(int k = 1;k <= rr-sr;k++){
			if(simulate(sr, sc, k, rc-sc, map, cum, n, m)){
				min = Math.min(min, (rc-sc)*k);
			}
		}
		if(min == Integer.MAX_VALUE){
			out.println(-1);
		}else{
			out.println(min);
		}
	}
	
	boolean simulate(int r, int c, int h, int w, char[][] map, int[][] cum, int n, int m)
	{
		int area = 0;
		if(cum[r+h][c+w] - cum[r][c+w] - cum[r+h][c] + cum[r][c] != h*w){
			return false;
		}
		area += h*w;
		
		while(true){
			boolean down = r+h < n && map[r+h][c] == 'X';
			boolean right = c+w < m && map[r][c+w] == 'X';
			if(down && right)return false;
			if(!down && !right){
				return area == cum[n][m];
			}
			
			if(right){
				c++;
				area += h;
			}else{
				r++;
				area += w;
			}
			if(cum[r+h][c+w] - cum[r][c+w] - cum[r+h][c] + cum[r][c] != h*w){
				return false;
			}
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