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
		State[] list = new State[n];
		for(int i = 0; i < n; i++)	{
			list[i] = new State(readInt(), readInt());
		}
		Arrays.sort(list);
		int ret = 0;
		int left = 1;
		for(State out: list)	{
			left--;
			left += out.b;
			ret += out.a;
			if(left == 0)
				break;
		}
		pw.println(ret);
		pw.close();
	}
	static class State implements Comparable<State> {
		public int a,b;
		public State(int x, int y)	{
			a=x;
			b=y;
		}
		public int compareTo(State s)	{
			if(b == s.b)
				return s.a - a;
			return s.b-b;
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