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
		TreeSet<State>[] col = new TreeSet[200005];
		TreeSet<State>[] row = new TreeSet[200005];
		TreeSet<State>[] diagL = new TreeSet[200005];
		TreeSet<State>[] diagR = new TreeSet[200005];
		for(int i = 0; i < col.length; i++)	{
			col[i] = new TreeSet<State>();
			row[i] = new TreeSet<State>();
			diagR[i] = new TreeSet<State>();
			diagL[i] = new TreeSet<State>();
		}
		readInt();
		int n = readInt();
		State[] list = new State[n];
		for(int i = 0; i < n; i++)	{
			int x = readInt();
			int y = readInt();
			list[i] = new State(x, y);
			col[y].add(list[i]);
			row[x].add(list[i]);
			diagL[x-y+100000].add(list[i]);
			diagR[x+y].add(list[i]);
		}
		int[] ret = new int[9];
		for(int i = 0; i < n; i++)	{
			int x = list[i].x;
			int y = list[i].y;
			int curr = 0;
			if(col[y].higher(list[i]) != null)
				curr++;
			if(col[y].lower(list[i]) != null)
				curr++;
			if(row[x].higher(list[i]) != null)
				curr++;
			if(row[x].lower(list[i]) != null)
				curr++;
			if(diagL[x-y+100000].higher(list[i]) != null)
				curr++;
			if(diagL[x-y+100000].lower(list[i]) != null)
				curr++;
			if(diagR[x+y].higher(list[i]) != null)
				curr++;
			if(diagR[x+y].lower(list[i]) != null)
				curr++;
			ret[curr]++;
		}
		StringBuilder sb = new StringBuilder();
		for(int out: ret)	{
			sb.append(out + " ");
		}
		pw.println(sb.toString().trim());
		pw.close();
	}

	static class State implements Comparable<State> {
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int compareTo(State s)	{
			if(x != s.x)
				return x - s.x;
			return y - s.y;
		}
	}
	
	/* NOTEBOOK CODE */

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