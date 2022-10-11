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

	static final long MOD = 1000000007;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			double ret = 0;
			int num = 0;
			for(int i = 1; i <= n; i++)	{
				num += readInt();
				ret = Math.max(ret, 1.0*num/i);
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static boolean valid(int[] order)	{
		for(int k = 0; k < order.length; k++)	{
			int curr = order[k];
			boolean[] seen = new boolean[order.length];
			while(true)	{
				if(seen[curr])	{
					break;
				}
				seen[curr] = true;
				curr = order[curr];
			}
			if(!seen[0])	{
				return false;
			}
		}
		return true;
	}
	
	public static long solve(int index, int[] order)	{
		if(index == order.length)	{
			return valid(order) ? 1 : 0;
		}
		long ret = 0;
		for(int i = 0; i < order.length; i++)	{
			order[index] = i;
			ret += solve(index+1, order);
		}
		return ret;
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