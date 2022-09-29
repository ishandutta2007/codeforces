//package round505;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] co = new int[m][];
		int[][] coto = new int[m][];
		for(int i = 0;i < m;i++){
			co[i] = new int[]{ni()-1, ni()-1, i};
		}
		for(int i = 0;i < m;i++){
			coto[i] = new int[]{ni()-1, ni()-1, i, -1};
		}
		
		int[][] coc = new int[m][];
		for(int i = 0;i < m;i++)coc[i] = Arrays.copyOf(co[i], 2);
		int[][] cotoc = new int[m][];
		for(int i = 0;i < m;i++)cotoc[i] = Arrays.copyOf(coto[i], 2);
		
		boolean[][] map = new boolean[n][n];
		for(int i = 0;i < m;i++){
			map[co[i][0]][co[i][1]] = true;
		}
		
		int[] who = new int[m];
		Arrays.fill(who, -1);
		List<String> ans = new ArrayList<>();
		
		
//		Arrays.sort(co, new Comparator<int[]>() {
//			public int compare(int[] a, int[] b) {
//				if(a[1] != b[1])return -(a[1] - b[1]);
//				return -(a[0] - b[0]);
//			}
//		});

		boolean[] done = new boolean[m];
		int ndone = 0;
		
		while(ndone < m){
			outer:
			for(int i = 0;i < m;i++){
				if(done[i])continue;
				for(int j = 0;j < m;j++){
					if(who[j] == -1){
						int[] route = route(map, co[i][0], co[i][1], j, n-1);
						if(route == null)continue;
						
						trans(co[i][0], co[i][1], route, ans);
						map[co[i][0]][co[i][1]] = false;
						co[i][0] = j; co[i][1] = n-1;
						who[j] = co[i][2];
						map[co[i][0]][co[i][1]] = true;
						done[i] = true;
						ndone++;
						continue outer;
					}
				}
//				throw new RuntimeException();
			}
		}
		
		
		Arrays.sort(coto, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		
		int p = 0;
		for(int i = 0;i < m;i++){
			if(i == 0 || coto[i][0] != coto[i-1][0]){
				p = 0;
			}else{
				p++;
			}
			coto[i][3] = p;
			int ind = coto[i][2];
			int[] route = route(map, co[ind][0], co[ind][1], coto[i][0], p);
			assert route != null;
			trans(co[ind][0], co[ind][1], route, ans);
			map[co[ind][0]][co[ind][1]] = false;
			co[ind][0] = coto[i][0]; 
			co[ind][1] = p;
			map[co[ind][0]][co[ind][1]] = true;
		}
		
		for(int i = m-1;i >= 0;i--){
			int ind = coto[i][2];
			int[] route = route(map, co[ind][0], co[ind][1], coto[i][0], coto[i][1]);
			if(route == null)continue;
			trans(co[ind][0], co[ind][1], route, ans);
			map[co[ind][0]][co[ind][1]] = false;
			co[ind][0] = coto[i][0]; 
			co[ind][1] = coto[i][1];
			map[co[ind][0]][co[ind][1]] = true;
		}
		
		out.println(ans.size());
		for(String line : ans){
			out.println(line);
		}
		
		check(ans, coc, cotoc, n);
	}
	
	void check(List<String> ans, int[][] coc, int[][] cotoc, int n)
	{
		assert ans.size() <= 10800;
		int[][] map = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(map[i], -1);
		}
		int m = coc.length;
		for(int i = 0;i < m;i++){
			map[coc[i][0]][coc[i][1]] = i;
		}
		
		for(String line : ans){
			String[] sp = line.split(" ");
			int r = Integer.parseInt(sp[0])-1;
			int c = Integer.parseInt(sp[1])-1;
			int nr = Integer.parseInt(sp[2])-1;
			int nc = Integer.parseInt(sp[3])-1;
			assert Math.abs(r-nr)+Math.abs(c-nc) == 1;
			assert map[r][c] != -1;
			assert map[nr][nc] == -1;
			map[nr][nc] = map[r][c];
			map[r][c] = -1;
		}
		
		for(int i = 0;i < m;i++){
			assert map[cotoc[i][0]][cotoc[i][1]] == i;
		}
	}
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	
	int[] dr = { 1, 0, -1, 0 };
	int[] dc = { 0, 1, 0, -1 };
	
	void trans(int r, int c, int[] route, List<String> ans)
	{
		for(int k : route){
			int nr = r + dr[k], nc = c + dc[k];
			ans.add((r+1) + " " + (c+1) + " " + (nr+1) + " " + (nc+1));
			r = nr; c = nc;
		}
	}
	
	int[] route(boolean[][] map, int sr, int sc, int tr, int tc)
	{
		assert map[sr][sc];
		if(sr == tr && sc == tc)return new int[0];
		if(map[tr][tc])return null;
		map[sr][sc] = false;
		int n = map.length;
		int[] q = new int[n*n];
		int p = 0;
		q[p++] = tr*n+tc;
		int[][] prev = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(prev[i], -1);
		}
		prev[tr][tc] = 999;
		
		for(int z = 0;z < p;z++){
			int cur = q[z];
			int r = cur/n, c = cur%n;
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < n && !map[nr][nc] && prev[nr][nc] == -1){
					prev[nr][nc] = k;
					q[p++] = nr*n+nc;
				}
			}
		}
		map[sr][sc] = true;
		if(prev[sr][sc] == -1)return null;
		
		int[] route = new int[n*n];
		int o = 0;
		int r = sr, c = sc;
		while(prev[r][c] != 999){
			int k = prev[r][c];
			r -= dr[k]; c -= dc[k];
			route[o++] = k^2;
		}
		return Arrays.copyOf(route, o);
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