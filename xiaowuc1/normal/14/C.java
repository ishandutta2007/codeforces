import java.util.*;
public class C14 {
	static int[][] grid;
	public static void main(String[] args)	{
		Scanner scan = new Scanner(System.in);
		grid = new int[4][4];
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				grid[i][j] = scan.nextInt();
		fix(0);
		fix(1);
		fix(2);
		fix(3);
		for(int i = 0; i < 4; i++)	{
			for(int j = i+1; j < 4; j++)	{
				if(grid[i][0] != grid[j][0])
					continue;
				if(grid[i][1] != grid[j][1])
					continue;
				if(grid[i][2] != grid[j][2])
					continue;
				if(grid[i][3] != grid[j][3])
					continue;
				System.out.println("NO");
				return;
			}
		}
		Set<Integer> x = new HashSet<Integer>();
		Set<Integer> y = new HashSet<Integer>();
		x.add(grid[0][0]);
		x.add(grid[0][2]);
		y.add(grid[0][1]);
		y.add(grid[0][3]);
		x.add(grid[1][0]);
		x.add(grid[1][2]);
		y.add(grid[1][1]);
		y.add(grid[1][3]);
		x.add(grid[2][0]);
		x.add(grid[2][2]);
		y.add(grid[2][1]);
		y.add(grid[2][3]);
		x.add(grid[3][0]);
		x.add(grid[3][2]);
		y.add(grid[3][1]);
		y.add(grid[3][3]);
		if(x.size() != 2 || y.size() != 2)	{
			System.out.println("NO");
			return;
		}
		if((grid[0][0] == grid[0][2]) == (grid[0][1] == grid[0][3]))	{
			System.out.println("NO");
			return;
		}
		if((grid[1][0] == grid[1][2]) == (grid[1][1] == grid[1][3]))	{
			System.out.println("NO");
			return;
		}
		if((grid[2][0] == grid[2][2]) == (grid[2][1] == grid[2][3]))	{
			System.out.println("NO");
			return;
		}
		if((grid[3][0] == grid[3][2]) == (grid[3][1] == grid[3][3]))	{
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
	}
	public static void fix(int x)	{
		if(grid[x][0] > grid[x][2])	{
			int x1 = grid[x][0];
			int y1 = grid[x][1];
			int x2 = grid[x][2];
			int y2 = grid[x][3];
			grid[x][0] = x2;
			grid[x][1] = y2;
			grid[x][2] = x1;
			grid[x][3] = y1;
		}
		if(grid[x][0] == grid[x][2] && grid[x][1] > grid[x][3])		{
			int x1 = grid[x][0];
			int y1 = grid[x][1];
			int x2 = grid[x][2];
			int y2 = grid[x][3];
			grid[x][0] = x2;
			grid[x][1] = y2;
			grid[x][2] = x1;
			grid[x][3] = y1;
		}
	}
}