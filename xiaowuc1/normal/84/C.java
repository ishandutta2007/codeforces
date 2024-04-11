import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			TreeSet<State> set = new TreeSet<State>();
			int[] ret = new int[n];
			Arrays.fill(ret, 1 << 25);
			for(int i = 0; i < n; i++)	{
				set.add(new State(readInt(), readInt(), i));
			}
			int qqq = readInt();
			for(int i = 0; i < qqq; i++)	{
				int x = readInt();
				int y = readInt();
				State fake = new State(x,y,1);
				State curr = set.lower(fake);
				if(curr != null && Math.hypot(curr.x-x,y)<=curr.r)	{
					ret[curr.i] = Math.min(ret[curr.i], i);
				}
				curr = set.higher(fake);
				if(curr != null && Math.hypot(curr.x-x,y)<=curr.r)	{
					ret[curr.i] = Math.min(ret[curr.i], i);
				}
				curr = set.floor(fake);
				if(curr != null && Math.hypot(curr.x-x,y)<=curr.r)	{
					ret[curr.i] = Math.min(ret[curr.i], i);
				}
				curr = set.ceiling(fake);
				if(curr != null && Math.hypot(curr.x-x,y)<=curr.r)	{
					ret[curr.i] = Math.min(ret[curr.i], i);
				}
			}
			int count = 0;
			for(int i = 0; i < n; i++)	{
				if(ret[i] == 1 << 25)	{
					ret[i] = -1;
				}
				else	{
					count++;
					ret[i]++;
				}
			}
			pw.println(count);
			StringBuilder sb = new StringBuilder();
			for(int out: ret)	{
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int x,r,i;

		public State(int x, int r, int i) {
			super();
			this.x = x;
			this.r = r;
			this.i = i;
		}

		public int compareTo(State s)	{
			return x - s.x;
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