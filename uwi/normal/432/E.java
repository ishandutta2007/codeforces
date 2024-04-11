//package round246;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		n = ni();
		m = ni();
		int[][] map = new int[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(map[i], -1);
		}
		dfs(0, 0, map);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				out.print((char)('A' + map[i][j]));
			}
			out.println();
		}
	}
	
	int n, m;
	
	static class Prof
	{
		int len;
		int color;
		int nextColor;
		String cs;
		
		public Prof(int len, int color, int nextColor) {
			this.len = len;
			this.color = color;
			this.nextColor = nextColor;
			
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < len;i++)sb.append((char)('A' + color));
			sb.append((char)('A' + nextColor));
			cs = sb.toString();
		}

		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			builder.append("Prof [len=");
			builder.append(len);
			builder.append(", color=");
			builder.append(color);
			builder.append(", nextColor=");
			builder.append(nextColor);
			builder.append(", cs=");
			builder.append(cs);
			builder.append("]");
			return builder.toString();
		}
	}
	
	boolean dfs(int r, int c, int[][] map)
	{
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				out.print(map[i][j] ? '#' : '.');
//			}
//			out.println();
//		}
		if(r >= n){
			return true;
		}
		if(c >= m){
			return dfs(r+1, 0, map);
		}
		if(map[r][c] >= 0)return dfs(r, c+1, map);
		int len = Math.min(n-r, m-c);
		for(int i = r;i < n;i++){
			for(int j = c;j < m;j++){
				if(map[i][j] >= 0){
					len = Math.min(len, Math.max(i-r, j-c));
				}
			}
		}
		
		Prof[] colors = new Prof[len];
		for(int i = len;i >= 1;i--){
			int cptn = 0;
			for(int j = -1;j <= i;j++){
				for(int k = -1;k <= i;k++){
					if((j == -1 || j == i) && (k == -1 || k == i))continue;
					if(r+j >= 0 && r+j < n && c+k >= 0 && c+k < m && map[r+j][c+k] >= 0){
						cptn |= 1<<map[r+j][c+k];
					}
				}
			}
			int color = Integer.numberOfTrailingZeros(~cptn);
			int nr = r, nc = c+i;
			if(nc >= m){
				nr++;
				nc = 0;
			}
			int nextColor = 0;
			if(nr == n){
				nextColor = -1;
			}else{
				if(map[nr][nc] >= 0){
					nextColor = map[nr][nc];
				}else{
					int lcptn = 1<<color;
					int[] dr = { 1, 0, -1, 0 };
					int[] dc = { 0, 1, 0, -1 };
					for(int k = 0;k < 4;k++){
						int nnr = nr + dr[k], nnc = nc + dc[k];
						if(nnr >= 0 && nnr < n && nnc >= 0 && nnc < m && map[nnr][nnc] != -1){
							lcptn |= 1<<map[nnr][nnc];
						}
					}
					nextColor = Integer.numberOfTrailingZeros(~lcptn);
				}
			}
			colors[i-1] = new Prof(i, color, nextColor);
		}
		Arrays.sort(colors, new Comparator<Prof>() {
			public int compare(Prof a, Prof b) {
				return a.cs.compareTo(b.cs);
			}
		});
//		tr(r, c, colors);
		for(int i = 0;i < len;i++){
			int u = colors[i].len;
			// paint
			for(int j = 0;j < u;j++){
				for(int k = 0;k < u;k++){
					if(map[r+j][c+k] >= 0){
						throw new RuntimeException();
					}
					map[r+j][c+k] = colors[i].color;
				}
			}
			if(dfs(r, c+u, map))return true;
			for(int j = 0;j < u;j++){
				for(int k = 0;k < u;k++){
					map[r+j][c+k] = -1;
				}
			}
		}
		return false;
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