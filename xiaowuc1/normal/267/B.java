
import java.io.*;
import java.util.*;
public class P101 {
	static StreamTokenizer br;
	static State[] list;
	static int[][] grid;
	static int[] stack;
	static int top = 0;
	public static void main(String[] args) throws IOException	{
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		stack = new int[n+1];
		list = new State[n];
		grid = new int[7][7];
		for(int i = 1; i <= n; i++)	{
			int a = readInt();
			int b = readInt();
			list[i-1] = (new State(a,b));
			grid[a][b]++;
			grid[b][a]++;
		}
		boolean solve = false;
		for(int i = 0; i < 7; i++)	{
			int deg = 0;
			for(int j = 0; j < 7; j++)	{
				if(i != j)
					deg += grid[i][j];
			}
			if(deg%2 != 0)		{
				solve = true;
				euler(i);
				break;
			}
		}
		if(!solve)	{
			for(int i = 0; i < 7; i++)	{
				int deg = 0;
				for(int j = 0; j < 7; j++)	{
						deg += grid[i][j];
				}
				if(deg > 0)		{
					euler(i);
					break;
				}
			}
		}
		if(top < stack.length)
			System.out.println("No solution");
		else	{
			String[] ans = new String[n];
			int l = 0;
			for(int i = 1; i < stack.length; i++)		{
				outer: for(int k = 0; k < list.length; k++)		{
					if(list[k] != null && stack[i-1] == list[k].a && stack[i] == list[k].b)		{
						ans[l++] = (k+1 + " +");
						list[k] = null;
						break outer;
					}
					if(list[k] != null && stack[i-1] == list[k].b && stack[i] == list[k].a)		{
						ans[l++] = (k+1 + " -");
						list[k] = null;
						break outer;
					}
				}
			}
			if(l != ans.length)		{
				System.out.println("No solution");
			}
			else	{
				for(String ss: ans)
					System.out.println(ss);
			}
		}
	}
	public static void euler(int x)		{     
		for(int i = 0; i <= 6; i++)	{
			while(grid[x][i] > 0)	{
				grid[x][i]--;
				grid[i][x]--;
				euler(i);
			}
		}
		stack[top++] = x;
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
	static class State	{
		public int a,b;
		public State(int x, int y)		{
			a=x;
			b=y;
		}
	}
}