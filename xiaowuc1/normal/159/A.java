import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int d = readInt();
		String[] first = new String[n];
		String[] second = new String[n];
		int[] t = new int[n];
		for(int i = 0; i < n; i++)	{
			first[i] = nextToken();
			second[i] = nextToken();
			t[i] = readInt();
		}
		Set<State> set = new HashSet<State>();
		for(int i = 0; i < n; i++)	{
			for(int j = i+1; j < n; j++)	{
				if(t[j] - t[i] > d)
					break;
				if(t[j] == t[i])
					continue;
				if(first[i].equals(second[j]) && first[j].equals(second[i]))	{
					set.add(new State(first[i], second[i]));
				}
			}
		}
		pw.println(set.size());
		for(State out: set)
			pw.println(out);
		pw.close();
	}
	static class State	{
		public String first, second;
		public State(String a, String b)	{
			if(a.compareTo(b) < 0)	{
				first = a;
				second = b;
			}
			else	{
				first = b;
				second = a;
			}
		}
		public int hashCode()	{
			return 3137 * first.hashCode() + second.hashCode();
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return first.equals(s.first) && second.equals(s.second);
		}
		public String toString()	{
			return first + " " + second;
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