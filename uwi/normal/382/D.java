//package round224;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[] dr = { 1, 0, -1, 0 };
	int[] dc = { 0, 1, 0, -1 };
	String DIR = "v>^<";
	int n, m;
	char[][] map;
	
	void solve()
	{
		n = ni(); m = ni();
		map = nm(n,m);
		
		int[][] indeg = new int[n][m];
		for(int i = 1;i < n-1;i++){
			for(int j = 1;j < m-1;j++){
				if(map[i][j] != '#'){
					int k = DIR.indexOf(map[i][j]);
					if(map[i+dr[k]][j+dc[k]] != '#'){
						indeg[i+dr[k]][j+dc[k]]++;
					}
				}
			}
		}
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 1;i < n-1;i++){
			for(int j = 1;j < m-1;j++){
				if(map[i][j] != '#' && indeg[i][j] == 0){
					q.add(i<<16|j);
				}
			}
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>16, c = cur&65535;
			int k = DIR.indexOf(map[r][c]);
			if(map[r+dr[k]][c+dc[k]] != '#'){
				if(--indeg[r+dr[k]][c+dc[k]] == 0){
					q.add(r+dr[k]<<16|c+dc[k]);
				}
			}
		}
		for(int i = 1;i < n-1;i++){
			for(int j = 1;j < m-1;j++){
				if(indeg[i][j] > 0){
					out.println(-1);
					return;
				}
			}
		}
		
		int[][] d = new int[n][m];
		int max1 = -1, max2 = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '#'){
					for(int k = 0;k < 4;k++){
						int nr = i + dr[k], nc = j + dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m){
							int ind = DIR.indexOf(map[i+dr[k]][j+dc[k]]);
							if(ind >= 0 && (ind+2&3) == k){
								q.add(nr<<16|nc);
								d[nr][nc] = 1;
								int v = go(map, q, d);
								if(v > max1){
									max2 = max1;
									max1 = v;
								}else if(v > max2){
									max2 = v;
								}
							}
						}
					}
				}
			}
		}
		if(max1 == -1){
			out.println(0);
		}else{
			out.println(max1 + Math.max(max1-1, max2));
		}
	}
	
	int go(char[][] map, Queue<Integer> q, int[][] d)
	{
		int maxd = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>16, c = cur&65535;
			maxd = Math.max(maxd, d[r][c]);
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m){
					int ind = DIR.indexOf(map[r+dr[k]][c+dc[k]]);
					if(ind >= 0 && (ind+2&3) == k){
						d[nr][nc] = d[r][c] + 1;
						q.add(nr<<16|nc);
					}
				}
			}
		}
		return maxd;
	}
	
	void run() throws Exception
	{
//		int n = 10, m = 10;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		char[][] map = new char[n][m];
//		for(int i = 0;i < n;i++){
//			Arrays.fill(map[i], '#');
//		}
//		for(int i = 0;i < n*m/5;i++){
//			int r = gen.nextInt(n-2)+1;
//			int c = gen.nextInt(m-2)+1;
//			map[r][c] = DIR.charAt(gen.nextInt(4));
//		}
//		for(int i = 0;i < n;i++){
//			sb.append(new String(map[i]) + " ");
//			tr(new String(map[i]));
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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