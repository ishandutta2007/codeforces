//package round124;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = new char[n][m];
		for(int i = 0;i < n;i++){
			map[i]  = ns(m);
		}
		
		int sr = 0, sc = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'S'){
					sr = i; sc = j;
					map[sr][sc] = '.';
				}
			}
		}
		
		Queue<int[]> q = new ArrayDeque<int[]>();
		boolean[][] ved = new boolean[n][m];
		int[][][] vp = new int[n][m][];
		q.add(new int[]{sr, sc, 0, 0});
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1];
			for(int k = 0;k < 4;k++){
				int h = cur[2], w = cur[3];
				int nr = r + dr[k], nc = c + dc[k];
				if(nr < 0){
					nr += n;
					h--;
				}
				if(nr >= n){
					nr -= n;
					h++;
				}
				if(nc < 0){
					nc += m;
					w--;
				}
				if(nc >= m){
					nc -= m;
					w++;
				}
				if(map[nr][nc] == '.'){
					if(!ved[nr][nc]){
						ved[nr][nc] = true;
						vp[nr][nc] = new int[]{h, w};
						q.add(new int[]{nr, nc, h, w});
					}else{
						if(vp[nr][nc][0] == h && vp[nr][nc][1] == w){
						}else{
							out.println("Yes");
							return;
						}
					}
				}
			}
		}
		out.println("No");
	}
	
	
	
	void run() throws Exception
	{
//		int n = 5;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + n + "\n" );
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				if(i == n/2 && j == n/2){
//					sb.append('S');
//					continue;
//				}
//				sb.append(gen.nextInt(3)<=1 ? '#' : '.');
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();
//		tr(INPUT);
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}