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
			String str = nextToken();
			BigInteger ret = BigInteger.ONE;
			TreeSet<Character> set = new TreeSet<Character>();
			for(int i = 0; i < str.length(); i++)	{
				int cand = i == 0 ? 9 : 10;
				if(str.charAt(i) == '?')	{
					ret = ret.multiply(BigInteger.valueOf(cand));
				}
				else if(Character.isLetter(str.charAt(i)) && set.add(str.charAt(i)))	{
					cand -= set.size()-1;
					ret = ret.multiply(BigInteger.valueOf(cand));
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class Vertex	implements Comparable<Vertex> {
		public int x,y,w;

		public Vertex(int x, int y, int w) {
			super();
			this.x = x;
			this.y = y;
			this.w = w;
		}
		
		public int compareTo(Vertex curr)	{
			return w - curr.w;
		}
	}
	
	static class State	{
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
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