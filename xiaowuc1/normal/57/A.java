import java.io.*;
import java.util.*;
public class A57 {
	static int n;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int x1 = Integer.parseInt(st.nextToken());
		int y1 = Integer.parseInt(st.nextToken());
		int x2 = Integer.parseInt(st.nextToken());
		int y2 = Integer.parseInt(st.nextToken());
		int[] dx = new int[]{-1,1,0,0};
		int[] dy = new int[]{0,0,-1,1};
		int[][] grid = new int[n+1][n+1];
		for(int i = 0; i <= n; i++)
			Arrays.fill(grid[i], 1 << 20);
		grid[x1][y1] = 0;
		LinkedList<State> q = new LinkedList<State>();
		q.add(new State(x1,y1));
		while(!q.isEmpty())		{
			State curr = q.removeFirst();
			if(curr.x == x2 && curr.y == y2)
				break;
			for(int i = 0; i < 4; i++)		{
				int outX = curr.x + dx[i];
				int outY = curr.y + dy[i];
				if(isValid(outX, outY) && grid[outX][outY] > 1 + grid[curr.x][curr.y])	{
					grid[outX][outY] = 1 + grid[curr.x][curr.y];
					q.addLast(new State(outX, outY));
				}
			}
		}
		System.out.println(grid[x2][y2]);
	}
	public static boolean isValid(int x, int y)		{
		return x>=0 && y>=0 && x<=n && y<=n && ((x==0 || x==n) || (y==0 || y==n));
	}
	static class State {
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
	}
}