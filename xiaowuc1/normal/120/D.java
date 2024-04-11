import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class D {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int[][] grid = new int[r][c];
		for(int i = 0; i < r; i++)	{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < c; j++)	{
				grid[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[] row = new int[r];
		int[] col = new int[c];
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				row[i] += grid[i][j];
				col[j] += grid[i][j];
			}
		}
		int[] rowPartial = new int[r+1];
		int[] colPartial = new int[c+1];
		for(int i = 1; i < rowPartial.length; i++)	{
			rowPartial[i] = rowPartial[i-1] + row[i-1];
		}
		for(int i = 1; i < colPartial.length; i++)	{
			colPartial[i] = colPartial[i-1] + col[i-1];
		}
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int z = Integer.parseInt(st.nextToken());
		int ret = 0;
		for(int i = 1; i < rowPartial.length; i++)	{
			for(int j = i+1; j < rowPartial.length - 1; j++)	{
				int xx = rowPartial[i];
				int yy = rowPartial[j] - rowPartial[i];
				int zz = rowPartial[rowPartial.length-1] - rowPartial[j];
				if(x == xx && y == yy && z == zz)	{
					ret++;
				}
				else if(x == xx && z == yy && y == zz)	{
					ret++;
				}
				else if(y == xx && x == yy && z == zz)	{
					ret++;
				}
				else if(y == xx && z == yy && x == zz)	{
					ret++;
				}
				else if(z == xx && x == yy && y == zz)	{
					ret++;
				}
				else if(z == xx && y == yy && x == zz)	{
					ret++;
				}
			}
		}
		for(int i = 1; i < colPartial.length; i++)	{
			for(int j = i+1; j < colPartial.length - 1; j++)	{
				int xx = colPartial[i];
				int yy = colPartial[j] - colPartial[i];
				int zz = colPartial[colPartial.length-1] - colPartial[j];
				if(x == xx && y == yy && z == zz)	{
					ret++;
				}
				else if(x == xx && z == yy && y == zz)	{
					ret++;
				}
				else if(y == xx && x == yy && z == zz)	{
					ret++;
				}
				else if(y == xx && z == yy && x == zz)	{
					ret++;
				}
				else if(z == xx && x == yy && y == zz)	{
					ret++;
				}
				else if(z == xx && y == yy && x == zz)	{
					ret++;
				}
			}
		}
		pw.println(ret);
		pw.close();
	}
}