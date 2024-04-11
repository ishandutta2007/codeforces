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
			int k = readInt();
			int sX = readInt();
			int sY = readInt();
			int eX = readInt();
			int eY = readInt();
			int nWanted = Math.max(0, eY-sY);
			int sWanted = Math.max(0, sY-eY);
			int wWanted = Math.max(0, sX-eX);
			int eWanted = Math.max(0, eX-sX);
			int n = 0;
			int s = 0;
			int w = 0;
			int e = 0;
			int ret = -1;
			String str = nextToken();
			for(int i = 0; i < str.length() && ret == -1; i++)	{
				if(str.charAt(i) == 'N')	{
					n++;
				}
				if(str.charAt(i) == 'E')	{
					e++;
				}
				if(str.charAt(i) == 'S')	{
					s++;
				}
				if(str.charAt(i) == 'W')	{
					w++;
				}
				if(n>=nWanted&&e>=eWanted&&s>=sWanted&&w>=wWanted)	{
					ret = i+1;
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