import java.io.*;
import java.util.*;
public class E16 {
	static double[][] grid;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		grid = new double[n][n];
		for(int i = 0; i < n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++)	{
				grid[i][j] = Double.parseDouble(st.nextToken());
			}
		}
		boolean[] seen = new boolean[1<<n];
		double[] prob = new double[1<<n];
		prob[(1<<n)-1] = 1;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add((1<<n)-1);
		while(!q.isEmpty())	{
			int curr = q.removeFirst();
			if(Integer.bitCount(curr) == 1)
				continue;
			for(int i = 0; i < n; i++)	{
				if((curr & (1 << i)) == 0)
					continue;
				for(int j = i+1; j < n; j++)		{
					if((curr & (1<<j)) == 0)
						continue;
					prob[curr-(1<<i)] += prob[curr] * grid[j][i];
					prob[curr-(1<<j)] += prob[curr] * grid[i][j];
					if(!seen[curr-(1<<i)])	{
						q.addLast(curr-(1<<i));
						seen[curr-(1<<i)] = true;
					}
					if(!seen[curr-(1<<j)])	{
						q.addLast(curr-(1<<j));
						seen[curr-(1<<j)] = true;
					}
				}
			}
			prob[curr] = 0;
		}
		double sum = 0;
		for(int i = 0; i < n; i++)		{
			sum += prob[1<<i];
		}
		for(int i = 0; i < n-1; i++)	{
			System.out.print(prob[1<<i]/sum + " ");
		}
		System.out.println(prob[1<<(n-1)]/sum);
	}
}