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
			ArrayList<State> list = new ArrayList<State>();
			int maxSize = 0;
			while(n-- > 0)	{
				list.add(new State(readInt(), readInt()));
				maxSize = Math.max(maxSize, list.get(list.size()-1).size);
			}
			Collections.sort(list);
			int ret = 0;
			for(int i = 0; i < list.size();)	{
				int j = i+1;
				int now = list.get(i).size;
				long currCount = list.get(i).count;
				while(j < list.size() && list.get(i).size == list.get(j).size)	{
					currCount += list.get(j++).count;
				}
				long a = 1;
				while(a == 1 || a < currCount)	{
					a *= 4;
					now++;
				}
				ret = Math.max(ret, now);
				i = j;
			}
			pw.println(ret);
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