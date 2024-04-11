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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			int[] list = new int[n];
			Arrays.fill(list, 1);
			list[n-1] = 0;
			int[] goal = new int[n];
			for(int i = 0; i < goal.length; i++)	{
				goal[i] = n-1-i;
			}
			while(k-- > 0)	{
				int[] useIndex = new int[n];
				int[] next = new int[n];
				for(int i = 0; i < list.length; i++)	{
					if(list[i] == goal[i])	{
						useIndex[i] = n-1;
						next[i] = list[i];
						continue;
					}
					for(int j = 0; j < n; j++)	{
						if(list[i] + list[j] <= goal[i])	{
							useIndex[i] = j;
							next[i] = list[i] + list[j];
							break;
						}
					}
				}
				list = next;
				StringBuilder sb = new StringBuilder();
				for(int out: useIndex)	{
					sb.append(++out + " ");
				}
				pw.println(sb.toString().trim());
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