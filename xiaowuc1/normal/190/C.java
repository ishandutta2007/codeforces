import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
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

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		outer: for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			ArrayList<Type> list = new ArrayList<Type>();
			st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) {
				String s = nextToken();
				if(s.equals("pair")) {
					list.add(new Pair(null, null));
				}
				else {
					list.add(new Element());
				}
				while(list.size() >= 3 && list.get(list.size()-3).emptyPair() && !list.get(list.size()-2).emptyPair() && !list.get(list.size()-1).emptyPair()) {
					Pair p = (Pair)list.remove(list.size()-3);
					Type l = list.remove(list.size()-2);
					Type r = list.remove(list.size()-1);
					p.l = l;
					p.r = r;
					list.add(p);
				}
			}
			if(list.size() != 1 || list.get(0).emptyPair()) {
				pw.println("Error occurred");
			}
			else {
				list.get(0).print();
				pw.println();
			}
		}
		exitImmediately();
	}

	static abstract class Type {
		public Type() {
			super();
		}
		public abstract void print();
		public abstract boolean emptyPair();
	}
	
	static class Element extends Type {
		public void print() {
			pw.print("int");
		}
		public boolean emptyPair() {
			return false;
		}
	}
	
	static class Pair extends Type {
		public Type l, r;
		public Pair(Type a, Type b) {
			l=a;
			r=b;
		}
		public boolean emptyPair() {
			return l == null && r == null;
		}
		public void print() {
			pw.print("pair<");
			l.print();
			pw.print(",");
			r.print();
			pw.print(">");
		}
	}
	
	static class State implements Comparable<State> {
		public int l, r;
		public State(int a, int b)  {
			l=a;
			r=b;
		}
		public int compareTo(State s) {
			return r - s.r;
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