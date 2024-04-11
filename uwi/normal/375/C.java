//package round221;
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
		int sr = -1, sc = -1;
		int[][] objs = new int[8][];
		int p = 0;
		int max = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'S'){
					sr = i; sc = j;
					map[sr][sc] = '.';
				}
				if(map[i][j] >= '1' && map[i][j] <= '9'){
					objs[p++] = new int[]{i, j, map[i][j]-'0'};
					max = Math.max(max, map[i][j]-'0');
				}
				if(map[i][j] == 'B'){
					objs[p++] = new int[]{i, j, -99999};
				}
			}
		}
		int[] price = na(max);
		for(int i = 0;i < p;i++){
			if(objs[i][2] >= 0){
				objs[i][2] = price[objs[i][2]-1];
			}
		}
		
		int I = 999999;
		int[][][] d = new int[n][m][1<<p];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				Arrays.fill(d[i][j], I);
			}
		}
		d[sr][sc][0] = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(enc(sr, sc, 0));
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>5&31, c = cur&31, ptn = cur>>>10;
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.'){
					int nptn = ptn;
					if(k == 2){
						for(int u = 0;u < p;u++){
							if(objs[u][0] == r && objs[u][1] < c)nptn ^= 1<<u;
						}
					}
					if(k == 0){
						for(int u = 0;u < p;u++){
							if(objs[u][0] == nr && objs[u][1] < nc)nptn ^= 1<<u;
						}
					}
					if(d[nr][nc][nptn] > d[r][c][ptn] + 1){
						d[nr][nc][nptn] = d[r][c][ptn] + 1;
						q.add(enc(nr, nc, nptn));
					}
				}
			}
		}
		
		long ret = 0;
		for(int i = 0;i < 1<<p;i++){
			long tot = 0;
			for(int j = 0;j < p;j++){
				if(i<<31-j<0){
					tot += objs[j][2];
				}
			}
			ret = Math.max(ret, tot - d[sr][sc][i]);
		}
		out.println(ret);
	}
	
	int enc(int r, int c, int ptn)
	{
		return ptn<<10|r<<5|c;
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