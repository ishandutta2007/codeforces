import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.LLOAD;


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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		final int MOD = 1000000007;
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String a = nextToken();
			String b = nextToken();
			int[] dp = new int[a.length()+1];
			for(int i = 0; i < b.length(); i++)	{
				int[] next = new int[a.length()+1];
				for(int j = 0; j <= a.length(); j++)
					next[j] = dp[j];
				for(int j = 0; j < a.length(); j++)	{
					if(a.charAt(j) == b.charAt(i))	{
						next[j+1]++;
						next[j+1] += dp[j];
						if(next[j+1] >= MOD)
							next[j+1] -= MOD;
					}
				}
				dp = next;
			}
			int ret = 0;
			for(int out: dp)	{
				ret += out;
				if(ret >= MOD)	{
					ret -= MOD;
				}
			}
			pw.println(ret);
		}
		pw.close();
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