import java.util.Scanner;

public class D {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int m=  sc.nextInt();
			char[][] grid= new char[n][m];
			int numG = 0;
			for(int i=0;i<n;i++) {
				String s = sc.next();
					for(int j=0;j<m;j++) {
						grid[i][j] = s.charAt(j);
						if(grid[i][j]=='G') numG++;
					}
			}
			int [] x = {0,1,0,-1};
			int [] y = {-1,0,1,0};
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(grid[i][j]=='B') {
						for(int a=0;a<4;a++) {
							int ni = i+x[a];
							int nj = j+y[a];
							if(inBounds(ni,nj,n,m)) {
								if(grid[ni][nj]=='.') {
									grid[ni][nj] = '#';
								}
							}
						}
					}
				}
			}
			if(grid[n-1][m-1]=='#') {
				if(numG>0) {
					System.out.println("No");
				}
				else {
					System.out.println("Yes");
				}
				continue;
			}
			boolean [][] visited = new boolean[n][m];
			counter =0;
			dfs(n-1,m-1,visited,grid);
			if(counter<0 || counter!=numG) {
				System.out.println("No");
			}
			else if(counter==numG) {
				System.out.println("Yes");
			
			}
			else {
				System.out.println("No");
			}
			
			
		}
	}
	static int counter;
	static void dfs(int i,int j, boolean [][] visited, char[][] grid) {
		visited[i][j] = true;
		if(grid[i][j]=='G') {
			counter++;
		}
		else if(grid[i][j]=='B'){
			counter = -1000000000;
			return;
		}
		int [] x = {0,1,0,-1};
		int [] y = {-1,0,1,0};
		for(int a=0;a<4;a++) {
			int ni = i+x[a];
			int nj = j+y[a];
			if(inBounds(ni,nj,grid.length,grid[0].length) && grid[ni][nj]!='#' && !visited[ni][nj]) {
				dfs(ni,nj,visited,grid);
			}
		}
	}
	
	static boolean inBounds(int x,int y,int n,int m) {
		return x>=0 && x<n && y>=0 && y<m;
	}
}