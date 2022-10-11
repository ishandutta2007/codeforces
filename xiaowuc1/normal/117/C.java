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

	static boolean[][] can;

	static boolean[] seen;
	static boolean[] processed;

	static ArrayList<Integer> cycle;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		can = new boolean[n][n];
		for(int i = 0; i < n; i++)	{
			String str = nextToken();
			for(int j = 0; j < n; j++)	{
				can[i][j] = str.charAt(j) == '1';
			}
		}
		cycle = new ArrayList<Integer>();
		seen = new boolean[n];
		processed = new boolean[n];
		boolean win = false;
		for(int i = 0; i < n; i++)	{
			if(!seen[i])	{
				win = dfs(i);
				if(win)	{
					break;
				}
			}
		}
		if(!win)	{
			pw.println(-1);
		}
		else	{
			boolean done = false;
			while(cycle.size() > 3)	{
				if(can[cycle.get(cycle.size()-1)][cycle.get(cycle.size()-3)])	{
					while(cycle.size() > 3)	{
						cycle.remove(cycle.size()-4);
					}
				}
				else	{
					cycle.remove(cycle.size()-2);
				}
			}
			if(!done)	{
				pw.println((cycle.get(0)+1) + " " + (cycle.get(1)+1) + " " + (cycle.get(2)+1));
			}
		}
		pw.close();
	}

	public static boolean dfs(int curr)	{
		if(processed[curr])
			return false;
		if(seen[curr])	{
			return true;
		}
		seen[curr] = true;
		for(int k = 0; k < can[curr].length; k++)	{
			if(can[curr][k])	{
				if(dfs(k))	{
					processed[curr] = true;
					cycle.add(0, curr);
					return true;
				}
			}
		}
		processed[curr] = true;
		return false;
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