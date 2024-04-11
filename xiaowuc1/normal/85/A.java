import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if(n==1)	{
			System.out.println("a\na\nb\nb");
		}
		else if(n == 2)		{
			System.out.println("aa\nbb\ncc\ndd");
		}
		else	{
			char[][] grid = new char[4][n];
			for(int i = 0; i + 1 < n; i+=2)	{
				if(i%4==2)	{
					grid[0][i] = grid[0][i+1] = 'e';
					grid[1][i] = grid[1][i+1] = 'f';
				}
				else	{
					grid[0][i] = grid[0][i+1] = 'a';
					grid[1][i] = grid[1][i+1] = 'b';
				}
			}
			for(int i = 1; i + 1 < n; i+=2)	{
				if(i%4==3)	{
					grid[2][i] = grid[2][i+1] = 'a';
					grid[3][i] = grid[3][i+1] = 'b';
				}
				else	{
					grid[2][i] = grid[2][i+1] = 'c';
					grid[3][i] = grid[3][i+1] = 'd';
				}
			}
			if(n%2==0)		{
				grid[2][0] = grid[3][0] = 'x';
				grid[2][n-1] = grid[3][n-1] = 'y';
			}
			else	{
				grid[2][0] = grid[3][0] = 'x';
				grid[0][n-1] = grid[1][n-1] = 'y';
			}
			System.out.println(new String(grid[0]));
			System.out.println(new String(grid[1]));
			System.out.println(new String(grid[2]));
			System.out.println(new String(grid[3]));
		}
	}
}