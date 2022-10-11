
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int n = readInt();
		int m = readInt();
		long[] ret = new long[n];
		PriorityQueue<State> q = new PriorityQueue<State>(n, new TimeComparator());
		for(int i = 0; i < n; i++)	{
			q.add(new State(i, readInt(), readInt()));
		}
		long currTime = 0;
		while(!q.isEmpty())	{
			ArrayList<State> qq = new ArrayList<State>(m);
			while(!q.isEmpty() && qq.size() < m)	{
				State curr = q.poll();
				currTime = Math.max(currTime, curr.timeArrive);
				qq.add(curr);
			}
			Collections.sort(qq, new DistanceComparator());
			int currX = 0;
			for(int i = 0; i < qq.size();)	{
				int j = i+1;
				while(j < qq.size() && qq.get(i).loc == qq.get(j).loc)	{
					j++;
				}
				currTime += qq.get(i).loc - currX;
				currX = qq.get(i).loc;
				for(int a = i; a < j; a++)	{
					ret[qq.get(a).index] = currTime;
				}
				currTime += 1 + (j-i)/2;
				i=j;
			}
			currTime += currX;
		}
		pw.print(ret[0]);
		for(int i = 1; i < n; i++)
			pw.print(" " + ret[i]);
		pw.println();
		pw.close();
	}

	static class TimeComparator implements Comparator<State>	{
		public int compare(State a, State b)	{
			return a.timeArrive - b.timeArrive;
		}
	}

	static class DistanceComparator implements Comparator<State>	{
		public int compare(State a, State b)	{
			return a.loc - b.loc;
		}
	}

	static class State {
		public int index, timeArrive, loc;
		public State(int a, int b, int c)	{
			index=a;
			timeArrive=b;
			loc=c;
		}
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}