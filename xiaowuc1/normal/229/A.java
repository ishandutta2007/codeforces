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
		int ret = Integer.MAX_VALUE;
		int r = readInt();
		int c = readInt();
		TreeSet<Integer>[] rows = new TreeSet[r];
		for(int i = 0; i < r; i++)	{
			rows[i] = new TreeSet<Integer>();
			String str = nextToken();
			for(int j = 0; j < c; j++)	{
				if(str.charAt(j) == '1')	{
					rows[i].add(j);
					rows[i].add(j+c);
				}
			}
			if(rows[i].isEmpty())	{
				ret = -1;
			}
		}
		if(ret == -1)	{
			pw.println(ret);
		}
		else	{
			for(int a = 0; a < 2*c; a++)	{
				int curr = 0;
				for(int i = 0; i < r; i++)	{
					Integer go1 = rows[i].floor(a);
					Integer go2 = rows[i].ceiling(a);
					if(go1 == null)
						go1 = -(1<<25);
					if(go2 == null)
						go2 = 1<<25;
					curr += Math.min(go2-a, a-go1);
				}
				ret = Math.min(ret, curr);
				if(ret == 0)
					break;
			}
			pw.println(ret);
		}
		pw.close(); 
	}

	public static double dist(double a, double b, double c, double d)	{
		double x = a-c;
		double y = b-d;
		return Math.sqrt(x*x+y*y);
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