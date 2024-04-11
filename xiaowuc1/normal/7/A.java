import java.io.*;
public class A7 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean[][] grid = new boolean[8][8];
		for(int i = 0; i < 8; i++)	{
			String s = br.readLine();
			for(int j = 0; j < 8; j++)
				grid[i][j] = s.charAt(j) == 'W';
		}
		int ret = 146;
		for(int i = 0; i < 256; i++)	{
			outer: for(int j = 0; j < 256; j++)		{
				if(Integer.bitCount(i) + Integer.bitCount(j) >= ret)
					continue;
				for(int a = 0; a < 8; a++)	{ // row
					for(int b = 0; b < 8; b++)	{ // col
						if(!grid[a][b] && (i & (1 << a)) == 0 && (j & (1 << b)) == 0)
							continue outer;
						if(grid[a][b] && ((i & 1 << a) != 0 || (j & (1 << b)) != 0))
							continue outer;
					}
				}
				ret = Math.min(ret, Integer.bitCount(i) + Integer.bitCount(j));
			}
		}
		System.out.println(ret);
	}
}