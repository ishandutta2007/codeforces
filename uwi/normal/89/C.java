//package round74;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "3 5\r\n" +
			".D...\r\n" +
			"RRRLL\r\n" +
			".U...";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		int[] dr = {0,0,-1,1};
		int[] dc = {-1,1,0,0};
		int[][][][] dir = new int[n][m][4][2];
		for(int k = 0;k < n;k++){
			for(int l = 0;l < m;l++){
				for(int u = 0;u < 4;u++){
					for(int v = 0;v < 2;v++){
						dir[k][l][u][v] = -1;
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] != '.'){
					for(int k = 0;k < 4;k++){
						int nr = i+dr[k];
						int nc = j+dc[k];
						while(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] == '.'){
							nr += dr[k];
							nc += dc[k];
						}
						
						if(nr >= 0 && nr < n && nc >= 0 && nc < m){
							dir[i][j][k][0] = nr;
							dir[i][j][k][1] = nc;
						}
					}
				}
			}
		}
		int[][][][] di = new int[n][m][4][2];
		for(int k = 0;k < n;k++){
			for(int l = 0;l < m;l++){
				for(int u = 0;u < 4;u++){
					for(int v = 0;v < 2;v++){
						di[k][l][u][v] = dir[k][l][u][v];
					}
				}
			}
		}
		
		int[][] ya = new int[20000][3];
		int p = 0;
		
		int max = 0;
		int maxct = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] != '.'){
					p = 0;
					int t;
					int r = i;
					int c = j;
					for(t = 0;r != -1;t++){
						int[] L = di[r][c][0];
						int[] R = di[r][c][1];
						int[] U = di[r][c][2];
						int[] D = di[r][c][3];
						if(L[0] != -1){
							di[L[0]][L[1]][1][0] = R[0];
							di[L[0]][L[1]][1][1] = R[1];
							ya[p][0] = L[0];
							ya[p][1] = L[1];
							ya[p][2] = 1;
							p++;
						}
						if(R[0] != -1){
							di[R[0]][R[1]][0][0] = L[0];
							di[R[0]][R[1]][0][1] = L[1];
							ya[p][0] = R[0];
							ya[p][1] = R[1];
							ya[p][2] = 0;
							p++;
						}
						if(U[0] != -1){
							di[U[0]][U[1]][3][0] = D[0];
							di[U[0]][U[1]][3][1] = D[1];
							ya[p][0] = U[0];
							ya[p][1] = U[1];
							ya[p][2] = 3;
							p++;
						}
						if(D[0] != -1){
							di[D[0]][D[1]][2][0] = U[0];
							di[D[0]][D[1]][2][1] = U[1];
							ya[p][0] = D[0];
							ya[p][1] = D[1];
							ya[p][2] = 2;
							p++;
						}
						
						int[] next;
						if(b[r][c] == 'L'){
							next = L;
						}else if(b[r][c] == 'R'){
							next = R;
						}else if(b[r][c] == 'U'){
							next = U;
						}else if(b[r][c] == 'D'){
							next = D;
						}else{
							next = null;
						}
						r = next[0];
						c = next[1];
					}
					if(t > max){
						max = t;
						maxct = 0;
					}
					if(t == max){
						maxct++;
					}
					
					for(int q = 0;q < p;q++){
						di[ya[q][0]][ya[q][1]][ya[q][2]][0] = dir[ya[q][0]][ya[q][1]][ya[q][2]][0];
						di[ya[q][0]][ya[q][1]][ya[q][2]][1] = dir[ya[q][0]][ya[q][1]][ya[q][2]][1];
					}
				}
			}
		}
		out.println(max + " " + maxct);
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
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}