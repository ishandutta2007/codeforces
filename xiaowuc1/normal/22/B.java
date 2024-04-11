import java.io.*;
import java.util.*;
public class B22 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		boolean[][] grid = new boolean[r][c];
		for(int i = 0; i < r; i++)		{
			String s = br.readLine();
			for(int j = 0; j < c; j++)
				grid[i][j] = s.charAt(j) == '0';
		}
		int max = 0;
		for(int minR = 0; minR < r; minR++)		{
			for(int maxR = minR; maxR < r; maxR++)		{
				int rDiff = maxR-minR+1;
				for(int minC = 0; minC < c; minC++)		{
					outer: for(int maxC = minC; maxC < c; maxC++)		{
						int cDiff = maxC-minC+1;
						if(2*rDiff+2*cDiff <= max)
							continue outer;
						for(int i = minR; i <= maxR; i++)		{
							for(int j = minC; j <= maxC; j++)		{
								if(!grid[i][j])
									continue outer;
							}
						}
						max = 2*(rDiff+cDiff);
					}
				}				
			}
		}
		System.out.println(max);
	}
}