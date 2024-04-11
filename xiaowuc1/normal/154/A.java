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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String curr = nextToken();
			int[][] dp = new int[curr.length()+1][26];
			for (int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i], 1 << 25);
			}
			int n = readInt();
			char[] bad = new char[26];
			while(n-- > 0)	{
				String op = nextToken();
				bad[op.charAt(0)-'a'] = op.charAt(1);
				bad[op.charAt(1)-'a'] = op.charAt(0);
			}
			for(int i = 0; i < curr.length(); i++)	{
				dp[i+1][curr.charAt(i)-'a'] = i;
				for(int k = 0; k < 26; k++)	{
					dp[i+1][k] = Math.min(dp[i+1][k], dp[i][k]+1);
					if(bad[k] != curr.charAt(i))	{
						dp[i+1][curr.charAt(i)-'a'] = Math.min(dp[i+1][curr.charAt(i)-'a'], dp[i][k]);
					}
				}
			}
			int ret = Integer.MAX_VALUE;
			for(int out: dp[curr.length()])	{
				ret = Math.min(ret, out);
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