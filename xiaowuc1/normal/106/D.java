import java.io.*;
import java.util.*;
public class D106 {
	static char[][] grid;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		grid = new char[r][];
		for(int i = 0; i < r; i++)
			grid[i] = br.readLine().toCharArray();
		int[] dist = new int[Integer.parseInt(br.readLine())];
		char[] dir = new char[dist.length]	;
		for(int i = 0; i < dist.length; i++)	{
			st = new StringTokenizer(br.readLine());
			dir[i] = st.nextToken().charAt(0);
			dist[i] = Integer.parseInt(st.nextToken());
		}
		int[][][] can = new int[r][c][4];
		// 0N1W2S3E
		for(int i = 0; i < r; i++)	{
			for(int j =0; j < c; j++)		{
				Arrays.fill(can[i][j], -1);
			}
		}
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				if(grid[i][j] != '#')	{
					can[i][j][0] = 0;
					can[i][j][1] = 0;
					if(i-1 >= 0)
						can[i][j][0] = Math.max(can[i][j][0], 1 + can[i-1][j][0]);
					if(j-1 >= 0)
						can[i][j][1] = Math.max(can[i][j][1], 1 + can[i][j-1][1]);
				}
			}
		}
		for(int i = r-1; i >= 0; i--)	{
			for(int j = c-1; j >= 0; j--)	{
				if(grid[i][j] != '#')	{
					can[i][j][2] = 0;
					can[i][j][3] = 0;
					if(i+1 < r)
						can[i][j][2] = Math.max(can[i][j][2], 1 + can[i+1][j][2]);
					if(j+1 < c)
						can[i][j][3] = Math.max(can[i][j][3], 1 + can[i][j+1][3]);
				}
			}
		}
		PriorityQueue<Character> q = new PriorityQueue<Character>();
		for(int i = 0; i < r; i++)	{
			outer: for(int j = 0; j < c; j++)	{
				if(Character.isLetter(grid[i][j]))	{
					int currX = i;
					int currY = j;
					for(int s = 0; s < dist.length; s++)	{
						int index = dir[s] == 'N' ? 0 : dir[s] == 'W' ? 1 : dir[s] == 'S' ? 2 : 3;
						if(can[currX][currY][index] < dist[s])	{
							continue outer;
						}
						if(index == 0)
							currX -= dist[s];
						if(index == 1)
							currY -= dist[s];
						if(index == 2)
							currX += dist[s];
						if(index == 3)
							currY += dist[s];
					}
					q.add(grid[i][j]);
				}
			}
		}
		if(q.isEmpty())	{
			System.out.println("no solution");
		}
		else	{
			while(!q.isEmpty())
				System.out.print(q.poll());
		}
	}
	public static boolean valid(int x, int y)	{
		return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length;
	}
}