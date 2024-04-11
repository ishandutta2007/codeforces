//package round41;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "a6 b4 c8 a8";
//	String INPUT = "a6 c4 b6 b8";
//	String INPUT = "a2 c1 a3 a1";
//	String INPUT = "a2 b1 b3 a1";
//	String INPUT = "b1 c1 b3 a1";
	String INPUT = "";
	
	void solve()
	{
		int[] r1 = co(in.next().toCharArray());
		int[] r2 = co(in.next().toCharArray());
		int[] wk = co(in.next().toCharArray());
		int[] bk = co(in.next().toCharArray());
		
		int[][] b = new int[8][8];
		b[r1[0]][r1[1]] = 1024;
		b[r2[0]][r2[1]] = 1024;
		b[wk[0]][wk[1]] = 1024;
		for(int i = wk[0] - 1;i <= wk[0] + 1;i++){
			for(int j = wk[1] - 1;j <= wk[1] + 1;j++){
				if(i >= 0 && i < 8 && j >= 0 && j < 8){
					b[i][j] |= 4;
				}
			}
		}
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};
		for(int j = 0;j < 4;j++){
			for(int i = 1;;i++){
				int xx = r1[0] + dx[j] * i;
				int yy = r1[1] + dy[j] * i;
				if(xx < 0 || xx >= 8 || yy < 0 || yy >= 8)break;
				if(b[xx][yy] >= 1024){
					b[xx][yy] |= 1;
					break;
				}
				b[xx][yy] |= 1;
			}
			for(int i = 1;;i++){
				int xx = r2[0] + dx[j] * i;
				int yy = r2[1] + dy[j] * i;
				if(xx < 0 || xx >= 8 || yy < 0 || yy >= 8)break;
				if(b[xx][yy] >= 1024){
					b[xx][yy] |= 2;
					break;
				}
				b[xx][yy] |= 2;
			}
		}
		
		for(int x = bk[0] - 1;x <= bk[0] + 1;x++){
			for(int y = bk[1] - 1;y <= bk[1] + 1;y++){
				if(x >= 0 && x < 8 && y >= 0 && y < 8){
					if(wk[0] == x && wk[1] == y){
						out.println("OTHER");
						return;
					}
					if((b[x][y] & 7) == 0){
						out.println("OTHER");
						return;
					}
				}
			}
		}
		out.println("CHECKMATE");
	}
	
	int[] co(char[] x)
	{
		return new int[]{x[0] - 'a', x[1] - '1'};
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}