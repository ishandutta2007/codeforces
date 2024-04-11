import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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
			char[] ret = new char[n];
			PriorityQueue<State> q = new PriorityQueue<Main.State>();
			for (int i = 0; i < ret.length; i++) {
				q.add(new State(readInt(),i));
				nextToken();
			}
			int a = 0;
			int b = 0;
			while(!q.isEmpty())	{
				State curr = q.poll();
				if(a + curr.a - b > 500)	{
					b += 1000 - curr.a;
					ret[curr.id] = 'G';
				}
				else	{
					ret[curr.id] = 'A';
					a += curr.a;
				}
			}
			pw.println(new String(ret));
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int a;
		public int id;
		public State(int a, int id) {
			super();
			this.a = a;
			this.id = id;
		}
		public int compareTo(State s)	{
			return a - s.a;
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