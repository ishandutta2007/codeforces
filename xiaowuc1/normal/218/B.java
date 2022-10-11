import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int amt = readInt();
		PriorityQueue<Integer> q1 = new PriorityQueue<Integer>();
		PriorityQueue<Integer> q2 = new PriorityQueue<Integer>();
		int n = readInt();
		while(n-- > 0)	{
			int k = readInt();
			q1.add(k);
			q2.add(-k);
		}
		int min = 0;
		int max = 0;
		while(amt-- > 0)	{
			int go = q1.poll();
			min += go--;
			if(go != 0)
				q1.add(go);
			go = q2.poll();
			max -= go++;
			if(go != 0)
				q2.add(go);
		}
		pw.println(max + " " + min);
		pw.close();
	}

	public static boolean isPrime(long k)	{
		if(k == 1)
			return false;
		int ret = 2;
		for(int i = 2; ret == 2 && i * i <= k; i++)	{
			if(k%i==0)
				ret++;
		}
		return ret == 2;
	}

	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int hashCode()		{
			return 3137*x+y;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return x == s.x && y == s.y;
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}