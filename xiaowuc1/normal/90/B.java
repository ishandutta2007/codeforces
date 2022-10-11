import java.io.*;
import java.util.*;
public class B90 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		char[][] grid = new char[r][c];
		for(int i = 0; i < r; i++)
			grid[i] = br.readLine().toCharArray();
		for(int i = 0; i < r; i++)	{
			outer: for(int j = 0; j < c; j++)	{
				for(int cc = 0; cc < c; cc++)	{
					if(j != cc && grid[i][j] == grid[i][cc])
						continue outer;
				}
				for(int rr = 0; rr < r; rr++)	{
					if(i != rr && grid[i][j] == grid[rr][j])
						continue outer;
				}
				System.out.print(grid[i][j]);
			}
		}
	}
}