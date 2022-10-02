//package strike2014.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int m = ni(), Q = ni();
		char[][] map = nm(2,m);
		int[][][][] d = new int[m][2][][];
		int[] offset = new int[m];
		Arrays.fill(offset, -1);
		go(0, m, Integer.highestOneBit(m-1), Integer.highestOneBit(m-1), d, offset, map);
		
		for(int q = 0;q < Q;q++){
			int f = ni()-1;
			int fr = f >= m ? 1 : 0;
			int fc = f - fr * m;
			int t = ni()-1;
			int tr = t >= m ? 1 : 0;
			int tc = t - tr * m;
			
			int xc = 0;
			if(fc == tc){
				xc = fc;
			}else{
				xc = Integer.highestOneBit(fc^tc);
				xc = Math.max(fc, tc)/xc*xc;
			}
			int ret = I;
//			tr("off", offset);
//			tr(xc, fr, fc, tr, tc);
			fc -= offset[xc];
			tc -= offset[xc];
//			tr("xc", xc, fr, fc, tr, tc, d[xc][0], offset[xc]);
			if(map[0][xc] == '.')ret = Math.min(ret, d[xc][0][fr][fc] + d[xc][0][tr][tc]);
			if(map[1][xc] == '.')ret = Math.min(ret, d[xc][1][fr][fc] + d[xc][1][tr][tc]);
			if(map[0][xc] == '.' && map[1][xc] == '.'){
				ret = Math.min(ret, d[xc][0][fr][fc] + d[xc][1][tr][tc] + 1);
				ret = Math.min(ret, d[xc][1][fr][fc] + d[xc][0][tr][tc] + 1);
			}
			if(ret == I){
				out.println(-1);
			}else{
				out.println(ret);
			}
		}
	}
	
	void go(int L, int R, int H, int B, int[][][][] d, int[] offset, char[][] map)
	{
		if(H < offset.length && offset[H] >= 0)return;
		if(B == 0){
			if(H < offset.length){
				offset[H] = L;
				if(map[0][H] == '.')d[H][0] = new int[][]{{0}, {map[1][H] == '.' ? 1 : I}};
				if(map[1][H] == '.')d[H][1] = new int[][]{{map[1][H] == '.' ? 1 : I}, {0}};
			}
			return;
		}
		if(H < offset.length){
			offset[H] = L;
			if(map[0][H] == '.')d[H][0] = distMap(map, 0, H, L, R);
			if(map[1][H] == '.')d[H][1] = distMap(map, 1, H, L, R);
		}
		go(L, Math.min(H, R), L+B/2, B/2, d, offset, map);
		go(H, R, H+B/2, B/2, d, offset, map);
	}
	static final int I = 999999999;
	
	int[][] distMap(char[][] map, int sr, int sc, int L, int R)
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int n = map.length;
		if(n == 0)return new int[0][0];
		int l = dr.length;
		int[][] d = new int[n][R-L];
		for(int i = 0;i < n;i++) {
			Arrays.fill(d[i], I);
		}
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(sr<<19|sc);
		d[sr][sc-L] = 0;
		
		int mask = (1<<19)-1;
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>19, c = cur&mask;
			for(int k = 0;k < l;k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= L && nc < R && map[nr][nc] == '.' && d[nr][nc-L] == I) {
					d[nr][nc-L] = d[r][c-L] + 1;
					q.add(nr<<19|nc);
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