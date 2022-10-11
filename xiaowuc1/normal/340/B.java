import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			State[] list = new State[n];
			for(int i = 0; i < n; i++) {
				list[i] = new State(readInt(), readInt());
			}
			double ret = 0;
			for(int i = 0; i < list.length; i++) {
				for(int j = i+1; j < list.length; j++) {
					double lHeight = 0;
					double rHeight = 0;
					double sideLength = dist(list[i], list[j]);
					for(int k = 0; k < list.length; k++) {
						if(k == i || k == j) continue;
						double angle = dot(list[i], list[j], list[k]);
						if(angle < 0) {
							lHeight = Math.max(lHeight, -angle);
						}
						else {
							rHeight = Math.max(rHeight, angle);
						}
					}
					if(lHeight == 0 || rHeight == 0) continue;
					ret = Math.max(ret, lHeight + rHeight);
				}
			}
			pw.println(ret/2);
		}
		exitImmediately();
	}

	public static double dot(State a, State b, State c) {
		return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
	}
	
	public static double dist(State a, State b) {
		double x = a.x - b.x;
		double y = a.y - b.y;
		return Math.sqrt(x*x+y*y);
	}
	
	public static double cross(State p, State q)   {
		return p.x*q.y-p.y*q.x;
	}
	public static double area(State a, State b, State c)	{
		return cross(a,b) + cross(b,c) + cross(c,a);
	}
	
	static class State implements Comparable<State> {
		public double x,y;
		public State(double a, double b)	{
			x=a;
			y=b;
		}
		public String toString()		{
			return x + " " + y;
		}
		public int compareTo(State s)	{
			if(y < s.y)
				return -1;
			else if(y > s.y)
				return 1;
			else if(x < s.x)
				return -1;
			else if(x > s.x)
				return 1;
			else
				return 0;
		}
	}

	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}