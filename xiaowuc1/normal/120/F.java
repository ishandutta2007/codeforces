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

	static boolean[] lose;

	static final long MOD = 1000000007;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int qq = readInt();
		int sum = 0;
		while(qq-- > 0)	{
			int ret = 0;
			int n = readInt();
			int[][] dist = new int[n][n];
			for(int i = 0; i < n; i++)	{
				Arrays.fill(dist[i], 1 << 25);
				dist[i][i] = 0;
			}
			for(int k = 1; k < n; k++)	{
				int a = readInt();
				int b = readInt();
				a--;
				b--;
				dist[a][b] = dist[b][a] = 1;
			}
			for(int k = 0; k < n; k++)	{
				for(int i = 0; i < n; i++)	{
					for(int j = 0; j < n; j++)	{
						dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
			for(int i = 0; i < n; i++)	{
				for(int j = 0; j < n; j++)	{
					ret = Math.max(ret, dist[i][j]);
				}
			}
			sum += ret;
		}
		pw.println(sum);
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