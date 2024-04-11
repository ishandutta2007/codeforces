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

	static final long MAX = 1L << 50;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int a = readInt();
			int b = readInt();
			if(a == b)	{
				StringBuilder sb = new StringBuilder();
				while(a-- > 0)	{
					readInt();
					sb.append("1 ");
				}
				while(b-- > 0)	{
					readInt();
					sb.append("2 ");
				}
				pw.println(sb.toString().trim());
			}
			else  {
				int[] list = new int[n];
				int[] count = new int[5];
				for (int i = 0; i < list.length; i++) {
					list[i] = readInt()-1;
					count[list[i]]++;
				}
				int temp = a;
				int[] want = new int[5];
				if(a < b)	{
					for(int k = 4; k >= 0; k--)	{
						for(int i = 0; i < count[k] && temp > 0; i++)	{
							want[k]++;
							temp--;
						}
					}
				}
				else	{
					for(int k = 0; k <= 4; k++)	{
						for(int i = 0; i < count[k] && temp > 0; i++)	{
							want[k]++;
							temp--;
						}
					}
				}
				StringBuilder sb = new StringBuilder();
				for(int out: list)	{
					if(--want[out] >= 0)	{
						sb.append("1 ");
					}
					else	{
						sb.append("2 ");
					}
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int size;
		public long count;

		public State(int size, long count) {
			super();
			this.size = size;
			this.count = count;
		}

		public int compareTo(State s)	{
			return s.size - size;
		}
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