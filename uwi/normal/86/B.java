//package yandex2011.r2;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 3 ... #.#";
//	String INPUT = "3 3\r\n" +
//			".#.\r\n" +
//			"...\r\n" +
//			"..#";
//	String INPUT = "3 3 ... .## .#.";
//	String INPUT = "1 2 ##";
//	String INPUT = "1000 1000 ";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		int[][] cl = new int[n*m][5];
		int[] clp = new int[n*m];
		
		int[][] fill = new int[n][m];
		int color = 1;
		int[] dr = {1,0,-1,0};
		int[] dc = {0,1,0,-1};
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '.' && j+1 < m && b[i][j+1] == '.'){
					fill[i][j] = color;
					fill[i][j+1] = color;
					b[i][j] = '@';
					b[i][j+1] = '@';
					cl[color][0] = i*m+j;
					cl[color][1] = i*m+j+1;
					clp[color] = 2;
					color++;
				}
				if(b[i][j] == '.' && i+1 < n && b[i+1][j] == '.'){
					fill[i][j] = color;
					fill[i+1][j] = color;
					b[i][j] = '@';
					b[i+1][j] = '@';
					cl[color][0] = i*m+j;
					cl[color][1] = (i+1)*m+j;
					clp[color] = 2;
					color++;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '.'){
					for(int k = 0;k < 4;k++){
						int nr = i + dr[k];
						int nc = j + dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] == '@'){
							fill[i][j] = fill[nr][nc];
							b[i][j] = '@';
							cl[fill[nr][nc]][clp[fill[nr][nc]]++] = i*m+j;
							break;
						}
					}
					if(b[i][j] == '.'){
						out.println(-1);
						return;
					}
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '@'){
					int col = fill[i][j];
					int mask = 0;
					for(int k = 0;k < clp[col];k++){
						int r = cl[col][k] / m;
						int c = cl[col][k] % m;
						for(int l = 0;l < 4;l++){
							int nr = r + dr[l];
							int nc = c + dc[l];
							if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] >= '0' && b[nr][nc] <= '9'){
								mask |= 1<<(b[nr][nc]-'0');
							}
						}
					}
					int f = 0;
					for(;f <= 9;f++){
						if(mask<<31-f>=0){
							break;
						}
					}
					for(int k = 0;k < clp[col];k++){
						int r = cl[col][k] / m;
						int c = cl[col][k] % m;
						b[r][c] = (char)('0' + f);
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			out.println(new String(b[i]));
		}
	}
	
	void run() throws Exception
	{
//		int n = 10;
//		StringBuilder sb = new StringBuilder(n + " " + n + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				sb.append(".");
//			}
//			sb.append(' ');
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}