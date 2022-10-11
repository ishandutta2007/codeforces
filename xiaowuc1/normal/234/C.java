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
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int n = readInt();
		int[] list = new int[n];
		int[] numNonpositive = new int[n];
		int[] numNonnegative = new int[n];
		for(int i = 0; i < list.length; i++)	{
			list[i] = readInt();
		}
		numNonnegative[0] = list[0] >= 0 ? 1 : 0;
		numNonpositive[n-1] = list[n-1] <= 0 ? 1 : 0;
		for(int i = 1; i < list.length; i++)	{
			numNonnegative[i] = numNonnegative[i-1] + (list[i] >= 0 ? 1 : 0);
			numNonpositive[n-1-i] = numNonpositive[n-i] + (list[n-1-i] <= 0 ? 1 : 0);
		}
		int ret = Integer.MAX_VALUE;
		for(int i = 1; i < n; i++)	{
			ret = Math.min(ret, numNonpositive[i] + numNonnegative[i-1]);
		}
		pw.println(ret);
		pw.close(); 
	}

	public static void gen(int[] list)	{
		StringBuilder sb = new StringBuilder();
		for(int i = 9; i >= 0; i--)	{
			while(list[i]-- > 0)	{
				if(i == 0 && sb.length() == 0)	{
					list[i] = 0;
				}
				sb.append(i);
			}
		}
		pw.println(sb.toString());
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