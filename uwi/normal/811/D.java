//package round416;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class DT {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int[] dr = { 1, 0, -1, 0 };
	int[] dc = { 0, 1, 0, -1 };
	char[] D = "DRUL".toCharArray();
	
	int[] move(int k)
	{
		out.println(D[k]);
		out.flush();
		return new int[]{ni()-1, ni()-1};
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++){
			map[i] = in.next().toCharArray();
		}
		int fr = -1, fc = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'F'){
					fr = i; fc = j;
				}
			}
		}
		int[][] ds = distMap(map, fr, fc);
		int[] cur = null;
		if(m >= 2 && ds[0][0] > ds[0][1]){
			cur = move(1);
			if(cur[1] == 1){
			}else{
				char c = D[1]; D[1] = D[3]; D[3] = c;
			}
			while(ds[cur[0]][cur[1]] > 0){
				if(n >= 2 && ds[cur[0]][cur[1]] > ds[cur[0]+1][cur[1]]){
					cur = move(0);
					if(cur[0] == 1){
					}else{
						char c = D[0]; D[0] = D[2]; D[2] = c;
					}
					break;
				}
				cur = move(1);
			}
		}else{
			cur = move(0);
			if(cur[0] == 1){
			}else{
				char c = D[0]; D[0] = D[2]; D[2] = c;
			}
			while(ds[cur[0]][cur[1]] > 0){
				if(m >= 2 && ds[cur[0]][cur[1]] > ds[cur[0]][cur[1]+1]){
					cur = move(1);
					if(cur[1] == 1){
					}else{
						char c = D[1]; D[1] = D[3]; D[3] = c;
					}
					break;
				}
				cur = move(0);
			}
		}
		while(ds[cur[0]][cur[1]] > 0){
			for(int k = 0;k < 4;k++){
				int nr = cur[0] + dr[k], nc = cur[1] + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && ds[cur[0]][cur[1]] > ds[nr][nc]){
					cur = move(k);
					break;
				}
			}
		}
	}
	
	public static int[][] distMap(char[][] map, int sr, int sc)
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int n = map.length;
		if(n == 0)return new int[0][0];
		int m = map[0].length;
		int l = dr.length;
		int[][] d = new int[n][m];
		int I = 999999999;
		for(int i = 0;i < n;i++) {
			Arrays.fill(d[i], 999999999);
		}
		
		int B = Integer.numberOfTrailingZeros(Integer.highestOneBit(m))+1;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(sr<<B|sc);
		d[sr][sc] = 0;
		
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>B, c = cur&(1<<B)-1;
			for(int k = 0;k < l;k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] != '*' && d[nr][nc] == I) { // fix
					d[nr][nc] = d[r][c] + 1;
					q.add(nr<<B|nc);
				}
			}
		}
		return d;
	}

	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new DT().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}