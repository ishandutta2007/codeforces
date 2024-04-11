//package neerc2017;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class I2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), q = ni(), P = ni();
		d = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				d[i][j] = 99999;
			}
		}
		qs = new int[n*m+5];
		
		char[][] map = nm(n,m);
		long[][] level = new long[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] >= 'A' && map[i][j] <= 'Z'){
					go(i, j, (map[i][j]-'A'+1)*q, map, level);
				}
			}
		}
		int ct = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(level[i][j] > P)ct++;
			}
		}
		out.println(ct);
	}
	
	int[][] d;
	int[] qs;
	
	void go(int sr, int sc, int power, char[][] map, long[][] level)
	{
		int qp = 0;
		qs[qp++] = sr<<16|sc;
		d[sr][sc] = 0;
		int n = map.length, m = map[0].length;
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int z = 0;z < qp;z++){
			int cur = qs[z];
			int r = cur>>>16, c = cur&65535;
			level[r][c] += power>>>d[r][c];
			if(d[r][c] < 30){
				for(int k = 0;k < 4;k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] != '*' && d[nr][nc] > d[r][c] + 1){
						d[nr][nc] = d[r][c] + 1;
						qs[qp++] = nr<<16|nc;
					}
				}
			}
		}
		for(int i = 0;i < qp;i++){
			d[qs[i]>>>16][qs[i]&65535] = 99999;
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
	
	public static void main(String[] args) throws Exception { new I2().run(); }
	
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