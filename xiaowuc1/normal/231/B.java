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

	
	
	static boolean[][] grid;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int last = readInt();
		int max = readInt();
		int[] list = new int[n];
		int ret = 0;
		for(int i = 0; i < n; i++)	{
			if(i%2==0)	{
				list[i] = 1;
				ret++;
			}
			else	{
				list[i] = max;
				ret -= max;
			}
		}
		if(last < ret)	{
			pw.println(-1);
		}
		else	{
			boolean bad = false;
			outer: while(ret != last)	{
				for(int i = 0; i < n; i++)	{
					if(i%2 == 0)	{
						if(list[i] == max)
							continue;
						list[i]++;
						ret++;
						continue outer;
					}
					else	{
						if(list[i] == 1)
							continue;
						list[i]--;
						ret++;
						continue outer;
					}
				}
				bad = true;
				break;
			}
			if(bad)	{
				pw.println(-1);
			}
			else	{
				StringBuilder sb = new StringBuilder();
				for(int out: list)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
			}
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