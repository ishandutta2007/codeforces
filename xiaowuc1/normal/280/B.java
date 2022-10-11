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

	static final long MOD = 1000000007;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			PriorityQueue<ValueState> q = new PriorityQueue<ValueState>();
			for(int i = 0; i < n; i++)	{
				q.add(new ValueState(i, readInt()));
			}
			long ret = 0;
			TreeSet<IndexState> set = new TreeSet<IndexState>();
			while(!q.isEmpty())	{
				ValueState curr = q.poll();
				IndexState transfer = new IndexState(curr.index, curr.value);
				if(set.lower(transfer) != null)	{
					ret = Math.max(ret, transfer.value ^ set.lower(transfer).value);
				}
				if(set.higher(transfer) != null)	{
					ret = Math.max(ret, transfer.value ^ set.higher(transfer).value);
				}
				set.add(transfer);
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class IndexState implements Comparable<IndexState>	{
		public int index, value;

		public IndexState(int index, int value) {
			super();
			this.index = index;
			this.value = value;
		}
		
		public int compareTo(IndexState i)	{
			return index - i.index;
		}
		
	}
	
	static class ValueState implements Comparable<ValueState>	{
		public int index, value;

		public ValueState(int index, int value) {
			super();
			this.index = index;
			this.value = value;
		}
		public int compareTo(ValueState s)	{
			return s.value - value;
		}
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