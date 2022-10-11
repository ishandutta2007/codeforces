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
			if(n%2==0)	{
				pw.println(-1);
			}
			else	{
				int[] a = new int[n];
				int[] b = new int[n];
				int[] c = new int[n];
				for(int i = 0; i < n; i++)	{
					a[i] = b[i] = i;
					c[i] = (2*i)%n;
				}
				StringBuilder sb = new StringBuilder();
				for(int out: a)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
				sb = new StringBuilder();
				for(int out: b)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
				sb = new StringBuilder();
				for(int out: c)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
				
			}
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