import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] prices = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			prices[i] = Integer.parseInt(st.nextToken());
		boolean[][] match = new boolean[n][n];
		while(m-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			match[a][b] = match[b][a] = true;
		}
		int best = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++)		{
			for(int j = i+1; j < n; j++)	{
				for(int k = j+1; k < n; k++)	{
					int test = prices[i] + prices[j] + prices[k];
					if(match[i][j] && match[i][k] && match[j][k])
						best = Math.min(best,test);
				}
			}
		}
		if(best == Integer.MAX_VALUE)
			best = -1;
		System.out.println(best);
	}
}