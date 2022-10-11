import java.awt.*;
import java.awt.event.*;
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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		boolean[] comp = new boolean[10000000];
		comp[0] = comp[1] = true;
		for(int i = 2; i * i < comp.length; i++)	{
			if(!comp[i])	{
				for(int j = i*i; j < comp.length; j += i)	{
					comp[j] = true;
				}
			}
		}
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] ret = new int[n];
			int c = 0;
			for(int i = 2; c < n; i++)	{
				if(!comp[i])	{
					ret[c++] = i;
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int out: ret)	{
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}