import java.io.*;
import java.util.*;
public class B27 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		boolean[][] grid = new boolean[n][n];
		for(int i = 1; i < (n*n-n)/2; i++)		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			grid[a][b] = true;
		}
		for(int i = 0; i < grid.length; i++)		{
			for(int j = i+1; j < grid[i].length; j++)		{
				if(!grid[i][j] && !grid[j][i])		{
					boolean[] seen = new boolean[n];
					seen[i] = true;
					LinkedList<Integer> q = new LinkedList<Integer>();
					q.add(i);
					while(!q.isEmpty())		{
						int curr = q.removeFirst();
						for(int k = 0; k < n; k++)		{
							if(!seen[k] && grid[curr][k])		{
								seen[k] = true;
								q.addLast(k);
							}
						}
					}
					if(seen[j])	{
						System.out.println((i+1) + " " + (j+1));
					}
					else	{
						System.out.println((j+1) + " " + (i+1));
					}
					return;
				}
			}
		}
	}
}