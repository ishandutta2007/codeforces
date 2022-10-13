import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C {
	static int n, m;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		 m = sc.nextInt();
		int t = sc.nextInt();
		int [][] grid = new int[n][m];
		for(int i=0;i<n;i++) {
			String s = sc.next();
			for(int j=0;j<m;j++) {
				if(s.charAt(j)=='1') {
					grid[i][j] = 1;
				}
			}
		}
		Queue<Point> q = new LinkedList<Point>();
		int [][] timeJoin = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				timeJoin[i][j] = -1;
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int [] dx = {-1,0,1,0};
				int [] dy = {0,1,0,-1};
				boolean has = false;
				for(int a=0;a<4;a++) {
					int nextX = dx[a]+i;
					int nextY = dy[a]+j;
					if(inBounds(nextX,nextY)) {
						if(grid[nextX][nextY]==grid[i][j]) {
							has = true;
						}
					}
				}
				if(has) {
					q.add(new Point(i,j));
					timeJoin[i][j] = 0;
				}
			}
		}
		while(!q.isEmpty()) {
			Point p = q.poll();
			int [] dx = {-1,0,1,0};
			int [] dy = {0,1,0,-1};
			int i = p.x;
			int j= p.y;
			for(int a=0;a<4;a++) {
				int nextX = dx[a]+i;
				int nextY = dy[a]+j;
				if(inBounds(nextX,nextY)) {
					if(timeJoin[nextX][nextY] == -1) {
						timeJoin[nextX][nextY] = timeJoin[i][j]+1;
						q.add(new Point(nextX,nextY));
					}
				}
			}
		}
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<m;j++) {
//				System.out.print(timeJoin[i][j] + " ");
//			}
//			System.out.println();
//		}
		StringBuilder sb = new StringBuilder();
		for(int a=0;a<t;a++) {
			int i = sc.nextInt()-1;
			int j = sc.nextInt()-1;
			long p = sc.nextLong();
			int ans =0 ;
			if(p>=(long) timeJoin[i][j] && timeJoin[i][j]>=0) {
				int x = (int) (p%2);
				int y = timeJoin[i][j]%2;
				ans = grid[i][j]+(x-y);
				ans%=2;
				if(ans<0) ans+=2;
			}
			else {
				ans = grid[i][j];
			}
			sb.append(ans);
			sb.append("\n");
		}
		System.out.println(sb.toString());
		
	}
	static boolean inBounds(int x,int y) {
		return x>=0 && x<n && y>=0 && y<m;
	}
	static class Point{
		int x;
		int y;
		public Point(int x,int y) {
			this.x = x; this. y = y;
		}
	}
}