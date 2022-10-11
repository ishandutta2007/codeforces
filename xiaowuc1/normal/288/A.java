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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			if(k > n)	{
				pw.println(-1);
			}
			else	{
				char[] list = new char[n];
				for(int i = 0; i < n; i++)	{
					list[i] = i%2==0?'a':'b';
				}
				int index = n-1;
				for(int a = k-1; a >= 2; a--)	{
					list[index--] = (char)('a'+a);
				}
				boolean valid = true;
				for(int i = 0; i < n-1; i++)	{
					if(list[i] == list[i+1]){
						valid = false;
					}
				}
				Set<Character> set = new HashSet<Character>();
				for(char out: list)	{
					set.add(out);
				}
				if(set.size() != k)	{
					valid = false;
				}
				if(valid)	{
					pw.println(new String(list));
				}
				else	{
					pw.println(-1);
				}
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