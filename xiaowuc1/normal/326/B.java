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

public class B {
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
			TreeSet<Integer>[] indices = new TreeSet[26];
			for (int i = 0; i < indices.length; i++) {
				indices[i] = new TreeSet<Integer>();
			}
			for(int i = 0; i < goal.length(); i++)	{
				indices[goal.charAt(i)-'a'].add(i);
			}
			int[][] dp = new int[51][goal.length()+1];
			int[][] parent = new int[51][goal.length()+1];
			for(int i = 0; i < dp.length; i++)	{
				Arrays.fill(dp[i], -1);
				Arrays.fill(parent[i], -1);
			}
			for(int i = 0; i < 26; i++)	{
				if(indices[i].size() >= 2)	{
					dp[1][indices[i].first()] = indices[i].last();
				}
			}
			for(int count = 1; count + 1 < dp.length; count++)	{
				int bestSeen = -1;
				for(int index = 0; index < dp[count].length; index++)	{
					if(dp[count][index] <= bestSeen) continue;
					bestSeen = dp[count][index];
					for(TreeSet<Integer> set: indices){
						Integer nextUp = set.higher(index);
						if(nextUp == null) continue;
						Integer nextBelow = set.lower(dp[count][index]);
						if(nextBelow == null) continue;
						if(nextBelow >= nextUp && nextBelow >= dp[count+1][nextUp])	{
							dp[count+1][nextUp] = nextBelow;
							parent[count+1][nextUp] = index;
						}
					}
				}
			}
			int bestCount = -1;
			int bestIndex = -1;
			int bestLen = -1;
			for(int i = dp.length-1; i >= 0; i--)	{
				for(int j = 0; j < dp[i].length; j++)	{
					if(dp[i][j] != -1)	{
						int candLen = 2 * i;
						if(j != dp[i][j])	{
							candLen++;
						}
						if(candLen > bestLen){
							bestCount = i;
							bestIndex = j;
							bestLen = candLen;
						}
					}
				}
			}
			if(bestLen == -1)	{
				pw.println(goal.charAt(0));
			}
			else	{
				String ret = "";
				while(bestCount > 0)	{
					if(dp[bestCount][bestIndex] == bestIndex)	{
						ret = goal.substring(bestIndex, bestIndex+1);
					}
					else	{
						ret = goal.charAt(bestIndex) + ret + goal.charAt(bestIndex);
					}
					bestIndex = parent[bestCount][bestIndex];
					bestCount--;
				}
				pw.println(ret);
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