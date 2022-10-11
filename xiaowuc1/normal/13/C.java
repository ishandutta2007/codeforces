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
		int n = readInt();
		int[] list = new int[n];
		int[] sorted = new int[n];
		loadArray(list);
		for(int i = 0; i < n; i++)
			sorted[i] = list[i];
		Arrays.sort(sorted);
		long[] dp = new long[n];
		dp[0] = Math.abs(list[0] - sorted[0]);
		for(int i = 1; i < n; i++)	{
			dp[i] = dp[i-1] + Math.abs(list[i] - sorted[0]);
		}
		for(int i = 1; i < n; i++)	{
			long[] nextDP = new long[n];
			nextDP[0] = Math.min(Math.abs(list[0] - sorted[i]), dp[0]);
			for(int k = 1; k < n; k++)	{
				nextDP[k] = Math.min(dp[k], nextDP[k-1] + Math.abs(list[k] - sorted[i]));
			}
			dp = nextDP;
		}
		pw.println(dp[n-1]);
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