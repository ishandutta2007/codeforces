import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int r = readInt();
		int c = readInt();
		int min = readInt();
		int max = readInt();
		char[][] grid = new char[r][c];
		for(int i = 0; i < r; i++)	{
			grid[i] = nextToken().toCharArray();
		}
		int[] num = new int[c];
		for(int j = 0; j < c; j++)	{
			for(int i = 0; i < r; i++)	{
				if(grid[i][j] == '#')	{
					num[j]++;
				}
			}
		}
		int[] firstDP = new int[c+1];
		int[] secondDP = new int[c+1];
		Arrays.fill(firstDP, 1 << 25);
		Arrays.fill(secondDP, 1 << 25);
		firstDP[0] = 0;
		secondDP[0] = 0;
		for(int i = 0; i < c; i++)	{
			int a = 0;
			int b = 0;
			for(int j = i; j < c; j++)	{
				a += num[j];
				b += r - num[j];
				if(j+1-i >= min && j+1-i <= max)	{
					secondDP[j+1] = Math.min(secondDP[j+1], firstDP[i] + a);
					firstDP[j+1] = Math.min(firstDP[j+1], secondDP[i] + b);
				}
			}
		}
		pw.println(Math.min(firstDP[c], secondDP[c]));
		pw.close();
	}

	/* NOTEBOOK CODE */

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}