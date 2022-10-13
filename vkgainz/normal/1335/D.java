import java.util.Scanner;

public class antisudoku {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb= new StringBuilder();
		while(t>0) {
			
			int [][] grid = new int[9][9];
			for(int i=0;i<9;i++) {
				String s = sc.next();
				for(int j=0;j<9;j++) {
					grid[i][j] = Integer.parseInt(s.substring(j,j+1));
				}
			}
			//change everything on main diagonal to 1s
			int[][] set = new int[9][2];
			for(int i=0;i<9;i++) {
				set[i][0] = i;
				set[i][1] = 3*(i%3)+i/3;
			}
			for(int i=0;i<9;i++) {
				//grid[i][3*(i%3)]
				int a = set[i][0]; int b = set[i][1];
				if(grid[a][b]==1) {
					grid[a][b]=0;
				}
				
				else {
					grid[a][b] = 1;
				}
			}
			for(int i=0;i<9;i++) {
				int a = set[i][0]; int b = set[i][1];
				if(grid[a][b] ==0) {
					if(b<8) {
						grid[a][b] = grid[a][b+1];
					}
					else{
						grid[a][b] = grid[a][b-1];
					}
				}
			}
			for(int i=0;i<9;i++) {
				for(int j=0;j<9;j++) {
					sb.append(grid[i][j]);
				}
				sb.append("\n");
			}
			sb.append("\n");
			t--;
		}
		System.out.println(sb.toString());
	}
}