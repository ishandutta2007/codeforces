import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int k = readInt();
		String str = nextToken();
		String ret = null;
		int cost = Integer.MAX_VALUE;
		for(int dig = 0; dig < 10; dig++)	{
			State[] list = new State[n];
			for(int i = 0; i < n; i++)
				list[i] = new State(Math.abs(dig - (str.charAt(i) - '0')), dig > str.charAt(i)-'0', i);
			Arrays.sort(list);
			int curr = 0;
			char[] go = str.toCharArray();
			for(int i = 0; i < k; i++)	{
				go[list[i].index] = (char)(dig+'0');
				curr += list[i].cost;
			}
			if(curr < cost)	{
				cost = curr;
				ret = new String(go);
			}
			else if(curr == cost && new String(go).compareTo(ret) < 0)	{
				ret = new String(go);
			}
		}
		pw.println(cost);
		pw.println(ret);
		pw.close();
	}

	static class State implements Comparable<State> {
		public int cost;
		public boolean increase;
		public int index;
		public State(int a, boolean b, int c)	{
			cost = a;
			increase = b;
			index = c;
		}
		public int compareTo(State s)	{
			if(cost != s.cost)
				return cost - s.cost;
			if(increase != s.increase)	{
				if(increase)
					return 1;
				return -1;
			}
			if(!increase)
				return index - s.index;
			return s.index - index;
		}
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}