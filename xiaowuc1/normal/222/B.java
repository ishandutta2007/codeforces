import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;
import static java.util.Collections.binarySearch;
import static java.util.Collections.shuffle;
import static java.util.Collections.sort;

public class B {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int r = readInt();
		int c = readInt();
		int qq = readInt();
		int[][] grid = new int[r][c];
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				grid[i][j] = readInt();
			}
		}
		int[] row = new int[r];
		int[] col = new int[c];
		for(int i = 0; i < r; i++)	{
			row[i] = i;
		}
		for(int i = 0; i < c; i++)	{
			col[i] = i;
		}
		while(qq-- > 0)	{
			String type = nextToken();
			int x = readInt();
			int y = readInt();
			x--;
			y--;
			if(type.equals("r"))	{
				int temp = row[x];
				row[x] = row[y];
				row[y] = temp;
			}
			else if(type.equals("c"))	{
				int temp = col[x];
				col[x] = col[y];
				col[y] = temp;
			}
			else	{
				pw.println(grid[row[x]][col[y]]);
			}
		}
		pw.close();
	}

	public static long readLong() throws IOException {
		return parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}