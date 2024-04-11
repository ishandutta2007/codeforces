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
		int[][] grid = new int[3][3];
		for(int i = 0; i < 3; i++)	{
			for(int j = 0; j < 3; j++)	{
				grid[i][j] = readInt();
			}
		}
		int min = 0;
		while(true)	{
			min++;
			grid[0][0] = min - grid[0][1] - grid[0][2];
			grid[1][1] = min - grid[1][0] - grid[1][2];
			grid[2][2] = min - grid[2][0] - grid[2][1];
			if(grid[0][0] + grid[1][1] + grid[2][2] == min && grid[0][2] + grid[1][1] + grid[2][0] == min)
				break;
		}
		for(int[] a: grid)	{
			StringBuilder sb = new StringBuilder();
			for(int b: a)	{
				sb.append(b + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close(); 
	}
	
	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
	}


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