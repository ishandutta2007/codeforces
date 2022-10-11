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

public class E {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	static final int MOD = 1000000007;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		long n = readLong();
		int m = readInt();
		int qq = readInt();
		long[][] grid = new long[m][m];
		n--;
		if(n == 0)	{
			pw.println(m);
		}
		else	{
			for(int i = 0; i < m; i++)	{
				Arrays.fill(grid[i], 1);
			}
			while(qq-- > 0)	{
				String str = nextToken();
				int index = str.charAt(0) >= 'a' && str.charAt(0) <= 'z' ? str.charAt(0) - 'a' : str.charAt(0) - 'A' + 26;
				int index2 = str.charAt(1) >= 'a' && str.charAt(1) <= 'z' ? str.charAt(1) - 'a' : str.charAt(1) - 'A' + 26;
				grid[index][index2] = 0;
			}
			long[][] ret = pow(grid, n);
			long ans = 0;
			for(long[] a: ret)
				for(long b: a)	{
					ans += b;
					if(ans >= MOD)
						ans -= MOD;
				}
			pw.println(ans);
		}
		pw.close();
	}

	public static long[][] pow(long[][] grid, long p)	{
		if(p == 1)	{
			return grid;
		}
		else if(p%2 == 0)	{
			long[][] a = pow(grid, p/2);
			return mult(a,a);
		}
		else	{
			long[][] a = pow(grid, p-1);
			return mult(a, grid);
		}
	}

	public static long[][] mult(long[][] a, long[][] b)	{
		long[][] ret = new long[a.length][a.length];
		for(int i = 0; i < a.length; i++)	{
			for(int j = 0; j < a[i].length; j++)	{
				for(int k = 0; k < b.length; k++)	{
					ret[i][k] += a[i][j] * b[j][k];
					ret[i][k] %= MOD;
				}
			}
		}
		return ret;
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