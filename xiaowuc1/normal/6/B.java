import java.io.*;
import java.util.*;
public class B6 {
	static char[][] grid;
	static Set<Character> ret;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ret = new HashSet<Character>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		char ch = st.nextToken().charAt(0);
		grid = new char[r][c];
		for(int i = 0; i < r; i++)
			grid[i] = br.readLine().toCharArray();
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				if(grid[i][j] == ch)	{
					deposit(i-1,j);
					deposit(i+1,j);
					deposit(i,j-1);
					deposit(i,j+1);
				}
		ret.remove(ch);
		System.out.println(ret.size());
	}
	public static void deposit(int x, int y)	{
		if(x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && Character.isLetter(grid[x][y]))
			ret.add(grid[x][y]);
	}
}