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
		boolean[] comp = new boolean[1100000];
		comp[0] = comp[1] = true;
		for(int i = 2; i * i < comp.length; i++)	{
			if(!comp[i])	{
				for(int j = i*i; j < comp.length; j += i)	{
					comp[j] = true;
				}
			}
		}
		int[] prefix = new int[comp.length+1];
		for(int i = 0; i < comp.length; i++)	{
			prefix[i+1] = prefix[i] + (!comp[i] ? 1 : 0);
		}
		int a = readInt();
		int b = readInt();
		int k = readInt();
		int min = 1;
		int max = b-a+2;
		while(min != max)	{
			int mid = (min+max)/2;
			boolean win = true;
			for(int i = a; win && i + mid - 1 <= b; i++)	{
				if(prefix[i+mid] - prefix[i] < k)
					win = false;
			}
			if(win)	{
				max = mid;
			}
			else	{
				min = mid+1;
			}
		}
		if(min == b-a+2)
			min = -1;
		pw.println(min);
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