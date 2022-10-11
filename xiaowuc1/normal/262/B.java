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
		int k = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		for(int i = 0; i < n && k > 0; i++)	{
			if(list[i] <= 0)	{
				list[i] = -list[i];
				k--;
			}
		}
		int best = 0;
		for(int i = 1; i < n; i++)	{
			if(Math.abs(list[i]) < Math.abs(list[best]))	{
				best = i;
			}
		}
		while(k > 0)	{
			list[best] = -list[best];
			k--;
		}
		long ret = 0;
		for(int out: list)
			ret += out;
		pw.println(ret);
		pw.close();
	}

	public static int numLucky(int n)	{
		int ret = 0;
		while(n > 0)	{
			if(n%10 == 4 || n%10 == 7)	{
				ret++;
			}
			n /= 10;
		}
		return ret;
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