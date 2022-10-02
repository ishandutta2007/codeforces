//package round139;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		
		int sr = -1, sc = -1;
		int gr = -1, gc = -1;
		int len = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '@'){
					gr = i; gc = j;
				}
				if(b[i][j] == '1'){
					sr = i; sc = j;
				}
				if(b[i][j] >= '1' && b[i][j] <= '9'){
					len = Math.max(len, b[i][j]-'0');
				}
			}
		}
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int sh;
		{
			int r = sr, c = sc;
			sh = 0;
			for(int i = 0;i < len-1;i++){
				for(int k = 0;k < 4;k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] == b[r][c] + 1){
						sh |= k<<2*i;
						r = nr; c = nc;
						break;
					}
				}
			}
		}
		
		int[][][] d = new int[n][m][1<<2*(len-1)];
		int I = 99999999;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				Arrays.fill(d[i][j], I);
			}
		}
		d[sr][sc][sh] = 0;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{sr, sc, sh});
		
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1], h = cur[2];
			if(r == gr && c == gc){
				out.println(d[r][c][h]);
				return;
			}
			inner:
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				int nh = (h<<2|(k^2))&(1<<2*(len-1))-1;
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] != '#' && d[nr][nc][nh] > d[r][c][h]+1){
					int ur = nr, uc = nc;
					for(int j = 0;j < len-1;j++){
						ur += dr[nh>>>2*j&3];
						uc += dc[nh>>>2*j&3];
						if(ur == nr && uc == nc){
							continue inner;
						}
					}
					d[nr][nc][nh] = d[r][c][h] + 1;
					q.add(new int[]{nr, nc, nh});
				}
			}
		}
		out.println(-1);
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
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
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