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

	static int[] numDigits;

	static final int MOD = 1000000007;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		numDigits = new int[12];
		numDigits[0] = -1;
		int max = readInt();
		dfs(Integer.toString(max), 0, true, 1);
		long ret = 0;
		for(int i = 1; i < numDigits.length; i++)	{
			if(numDigits[i] == 0)
				continue;
			for(int a = 0; a < i; a++)	{
				for(int b = 0; a+b<i; b++)	{
					for(int c = 0; a +b+c < i; c++)	{
						for(int d = 0; a+b+c+d < i; d++)	{
							for(int e = 0; a+b+c+d+e < i; e++)	{
								for(int f = 0; a+b+c+d+e+f < i; f++)	{
									int[] numCount = new int[12];
									numCount[a]++;
									numCount[b]++;
									numCount[c]++;
									numCount[d]++;
									numCount[e]++;
									numCount[f]++;
									long curr = numDigits[i];
									for(int k = 0; k < numCount.length; k++)	{
										for(int x = 0; x < numCount[k]; x++)	{
											curr *= numDigits[k] - x;
											curr %= MOD;
										}
									}
									ret += curr;
									ret %= MOD;
								}
							}
						}
					}
				}
			}
		}
		pw.println(ret);
		pw.close(); 
	}

	public static void dfs(String max, int numLucky, boolean match, int scale)	{
		if(max.length() == 0)	{
			numDigits[numLucky] += scale;
		}
		else	{
			if(match)	{
				int notLucky = 0;
				int lucky = 0;
				for(int i = 0; i < max.charAt(0) - '0'; i++)	{
					if(i == 4 || i == 7)
						lucky++;
					else
						notLucky++;
				}
				if(notLucky != 0)
					dfs(max.substring(1), numLucky, false, scale * notLucky);
				if(lucky != 0)
					dfs(max.substring(1), numLucky+1, false, scale * lucky);
				dfs(max.substring(1), numLucky + (max.charAt(0) == '4' || max.charAt(0) == '7' ? 1 : 0), true, scale);
			}
			else	{
				dfs(max.substring(1), numLucky, false, 8*scale);
				dfs(max.substring(1), numLucky+1, false, 2*scale);
			}
		}
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