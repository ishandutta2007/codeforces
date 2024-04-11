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
			long[] ret = new long[n+1];
			Set<Long> set = new HashSet<Long>();
			for(int i = 0; i <= n; i++)	{
				int curr = 0;
				for(int j = 0; j < 25; j++)	{
					if((i&(1<<j)) == 0)	{
						curr |= 1 << j;
					}
				}
				ret[i] = curr;
				for(int bit = 50; ret[i] > n || set.contains(ret[i]); bit--)	{
					if((ret[i]&(1L<<bit)) != 0)	{
						ret[i] &= ~(1L << bit);
					}
				}
				set.add(ret[i]);
			}
			StringBuilder sb = new StringBuilder();
			for(long out: ret)	{
				sb.append(out + " ");
			}
			pw.println(n * (n + 1L));
			pw.println(sb.toString().trim());
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