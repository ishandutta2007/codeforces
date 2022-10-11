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

public class A {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String goal = nextToken();
			int[] count = new int[26];
			for(int i = 0; i < goal.length(); i++)	{
				count[goal.charAt(i)-'a']++;
			}
			int numD = 0;
			for(int out: count)	{
				if(out > 0)	{
					numD++;
				}
			}
			int n = readInt();
			if(numD > n)	{
				pw.println(-1);
			}
			else	{
				int min = 1;
				int max = 10000;
				while(min != max)	{
					int mid = (min+max)/2;
					int use = 0;
					for(int out: count)	{
						int must = (out+mid-1)/mid;
						use += must;
					}
					if(use <= n)	{
						max = mid;
					}
					else	{
						min = mid+1;
					}
				}
				pw.println(min);
				StringBuilder sb = new StringBuilder();
				for(int i = 0; i < count.length; i++)	{
					int use = (count[i] + min-1) / min;
					while(use-- > 0)	{
						sb.append((char)('a'+i));
					}
				}
				while(sb.length() < n)	{
					sb.append("z");
				}
				pw.println(sb);
			}
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