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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int qqq = readInt();
			int total = readInt();
			int[] dp = new int[total+1];
			while(qqq-- > 0)	{
				int n = readInt();
				int[] list = new int[n];
				for(int i = 0; i < n; i++)	{
					list[i] = readInt();
				}
				int[] leftSum = new int[n+1];
				int[] rightSum = new int[n+1];
				for(int i = 0; i < n; i++)	{
					leftSum[i+1] = leftSum[i] + list[i];
					rightSum[i+1] = rightSum[i] + list[n-1-i];
				}
				int[] best = new int[n+1];
				for(int i = 0; i <= n; i++)	{
					for(int j = 0; j <= i; j++)	{
						best[i] = Math.max(best[i], leftSum[j] + rightSum[i-j]);
					}
				}
				for(int i = total; i >= 0; i--)	{
					for(int j = 0; j <= i && j <= n; j++)	{
						dp[i] = Math.max(dp[i], dp[i-j] + best[j]);
					}
				}
			}
			pw.println(dp[total]);
		}
		pw.close();
	}

	static class State	{
		public String a,b,c;

		public State(String a, String b, String c) {
			super();
			this.a = a;
			this.b = b;
			this.c = c;
		}

		public ArrayList<State> next()	{
			ArrayList<State> ret = new ArrayList<State>();
			if(a.length() > 0)	{
				ret.add(new State(a.substring(1), a.charAt(0) + b, c));
				ret.add(new State(a.substring(1), b, a.charAt(0) + c));
			}
			if(b.length() > 0)	{
				ret.add(new State(b.charAt(0) + a, b.substring(1), c));
				ret.add(new State(a, b.substring(1), b.charAt(0) + c));
			}
			if(c.length() > 0)	{
				ret.add(new State(a, c.charAt(0) + b, c.substring(1)));
				ret.add(new State(c.charAt(0) + a, b, c.substring(1)));
			}
			return ret;
		}
		
		public boolean valid()	{
			for(int i = 0; i < a.length()-1; i++)	{
				if(a.charAt(i) >= a.charAt(i+1))
					return false;
			}
			for(int i = 0; i < b.length()-1; i++)	{
				if(b.charAt(i) >= b.charAt(i+1))
					return false;
			}
			for(int i = 0; i < c.length()-1; i++)	{
				if(c.charAt(i) >= c.charAt(i+1))
					return false;
			}
			
			return true;
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((a == null) ? 0 : a.hashCode());
			result = prime * result + ((b == null) ? 0 : b.hashCode());
			result = prime * result + ((c == null) ? 0 : c.hashCode());
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
			if (a == null) {
				if (other.a != null)
					return false;
			} else if (!a.equals(other.a))
				return false;
			if (b == null) {
				if (other.b != null)
					return false;
			} else if (!b.equals(other.b))
				return false;
			if (c == null) {
				if (other.c != null)
					return false;
			} else if (!c.equals(other.c))
				return false;
			return true;
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