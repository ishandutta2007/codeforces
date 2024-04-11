import java.io.*;
import java.util.*;
public class B60 {
	static int ret;
	static boolean[][][] grid;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int k = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		br.readLine();
		grid = new boolean[k][m][n];
		for(int i = 0; i < k; i++)	{
			for(int j = 0; j < m; j++)	{
				String s = br.readLine();
				for(int l = 0; l < n; l++)	{
					grid[i][j][l] = s.charAt(l) == '.';
				}
			}
			br.readLine();
		}
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		dfs(0, --x, --y);
		System.out.println(ret);
	}
	public static void dfs(int x, int y, int z)	{
		if(!valid(x,y,z) || !grid[x][y][z])	{
			return;
		}
		ret++;
		grid[x][y][z] = false;
		dfs(x-1,y,z);
		dfs(x+1,y,z);
		dfs(x,y-1,z);
		dfs(x,y+1,z);
		dfs(x,y,z-1);
		dfs(x,y,z+1);
	}
	public static boolean valid(int x, int y, int z)	{
		return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && z >= 0 && z < grid[x][y].length;
	}
}