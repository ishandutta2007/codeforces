//package round209;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	boolean[][] ved;
	int n;
	int[][] a;
	int[] dr = { 1, 0, -1, 0 };
	int[] dc = { 0, 1, 0, -1 };
	String DIR = "DRUL";
	StringBuilder sb;
	int[][] ptns;
	
	void solve()
	{
		n = ni();
		int sr = ni()-1, sc = ni()-1;
		a = new int[n][];
		for(int i = 0;i < n;i++)a[i] = na(n);
		
		sb = new StringBuilder();
		
		ved = new boolean[n][n];
		ptns = new int[n][n];
		ved[sr][sc] = true;
		if(a[sr][sc] == 0){
			sb.append(1); a[sr][sc] = 1;
		}
		dfs(sr, sc, -1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(a[i][j] == 1 && !ved[i][j]){
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		dfs2(sr, sc, -1);
		sb.append(2);
		out.println(sb);
	}
	
	void dfs(int r, int c, int proh)
	{
		for(int k = 0;k < 4;k++){
			if(k == proh)continue;
			int to = 0;
			for(int i = 1, nr = r + dr[k], nc = c + dc[k];nr >= 0 && nr < n && nc >= 0 && nc < n;i++, nr += dr[k], nc += dc[k]){
				if(a[nr][nc] == 1){
					if(!ved[nr][nc]){
						to = i;
					}else{
						to = i-1;
					}
					break;
				}
			}
			if(to >= 1){
				int nr = r + dr[k], nc = c + dc[k];
				sb.append(DIR.charAt(k));
				if(a[nr][nc] == 0 || !ved[nr][nc]){
					ved[nr][nc] = true;
					if(a[nr][nc] == 0){
						sb.append(1);
						a[nr][nc] = 1;
					}
					ptns[r][c] |= 1<<k;
					dfs(nr, nc, k^2);
				}
				sb.append(DIR.charAt(k^2));
			}
		}
	}
	
	void dfs2(int r, int c, int proh)
	{
		for(int k = 0;k < 4;k++){
			if(ptns[r][c]<<~k<0){
				sb.append(DIR.charAt(k));
				int nr = r + dr[k], nc = c + dc[k];
				dfs2(nr, nc, k^2);
				assert a[nr][nc] == 1;
				sb.append(2);
				sb.append(DIR.charAt(k^2));
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 99999;
//		Random gen = new Random(1000000000);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(250 + " ");
//		sb.append(250 + " ");
//		for (int i = 0; i < n*n; i++) {
//			sb.append(gen.nextInt(2) + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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