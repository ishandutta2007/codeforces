//package round292;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int[][] deg = new int[n][m];
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.'){
					for(int k = 0;k < 4;k++){
						int ni = i + dr[k], nj = j + dc[k];
						if(ni >= 0 && ni < n && nj >= 0 && nj < m){
							if(map[ni][nj] == '.'){
								deg[i][j] |= 1<<k;
							}
						}
					}
				}
			}
		}
		Queue<int[]> q = new ArrayDeque<int[]>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.'){
					if(deg[i][j] == 0){
						out.println("Not unique"); return;
					}else if(Integer.bitCount(deg[i][j]) == 1){
						q.add(new int[]{i, j});
					}
				}
			}
		}
		
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1];
			if(map[r][c] != '.')continue;
			int k = Integer.numberOfTrailingZeros(deg[r][c]);
			int nr = r + dr[k], nc = c + dc[k];
			if(k == 0){
				map[r][c] = '^';
				map[nr][nc] = 'v';
			}else if(k == 2){
				map[r][c] = 'v';
				map[nr][nc] = '^';
			}else if(k == 1){
				map[r][c] = '<';
				map[nr][nc] = '>';
			}else{
				map[r][c] = '>';
				map[nr][nc] = '<';
			}
			deg[nr][nc]^=1<<(k^2);
			for(int i = 0;i < 4;i++){
				if(deg[nr][nc]<<~i<0){
					int nnr = nr+dr[i], nnc = nc+dc[i];
					deg[nnr][nnc] ^= 1<<(i^2);
					if(Integer.bitCount(deg[nnr][nnc]) == 1){
						q.add(new int[]{nnr, nnc});
					}
					if(Integer.bitCount(deg[nnr][nnc]) == 0){
						out.println("Not unique"); return;
					}
				}
			}
			deg[nr][nc] = 0;
			deg[r][c] = 0;
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.'){
					out.println("Not unique"); return;
				}
			}
		}
		for(int i = 0;i < n;i++){
			out.println(new String(map[i]));
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