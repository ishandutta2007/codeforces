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

	static int[] dx = new int[]{-1,0,0,0,1};
	static int[] dy = new int[]{0,-1,0,1,0};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			boolean[] comp = new boolean[1000000];
			comp[0] = comp[1] = true;
			for(int i = 2; i * i < comp.length; i++)	{
				if(!comp[i])	{
					for(int j = i * i; j < comp.length; j += i)	{
						comp[j] = true;
					}
				}
			}
			int r = readInt();
			int c = readInt();
			int[][] dp = new int[r][c];
			for(int i = 0; i < r; i++)	{
				for(int j = 0; j < c; j++)	{
					int curr = readInt();
					while(comp[curr++])	{
						dp[i][j]++;
					}
				}
			}
			int ret = Integer.MAX_VALUE;
			for(int[] out: dp)	{
				int curr = 0;
				for(int out2: out)	{
					curr += out2;
				}
				ret = Math.min(ret, curr);
			}
			for(int j = 0; j < c; j++)	{
				int curr = 0;
				for(int[] out: dp)	{
					curr += out[j];
				}
				ret = Math.min(ret, curr);
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static boolean good(int curr)	{
		String ret = String.valueOf(curr);
		Set<Character> set = new HashSet<Character>();
		for(int i = 0; i < ret.length(); i++)	{
			set.add(ret.charAt(i));
		}
		return set.size() == ret.length();
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