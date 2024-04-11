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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			Query[] queries = new Query[n];
			for(int i = 0; i < n; i++) {
				queries[i] = new Query(readInt(), readInt(), i);
			}
			int[] ret = new int[n];
			int m = readInt();
			Person[] p = new Person[m];
			for(int i = 0; i < m; i++) {
				int l = readInt();
				int r = readInt();
				int t = readInt();
				p[i] = new Person(l, r, i+1, t);
			}
			Arrays.sort(queries);
			Arrays.sort(p);
			int pIndex = m-1;
			TreeSet<State> set = new TreeSet<State>();
			boolean win = true;
			for(int i = n-1; i >= 0; i--) {
				Query curr = queries[i];
				while(pIndex >= 0 && p[pIndex].r >= curr.r) {
					State last = new State(p[pIndex].l, p[pIndex].index, p[pIndex].time);   
					set.add(last);
					pIndex--;
				}
				if(set.isEmpty() || set.first().lowerBound > curr.l) {
					win = false;
					break;
				}
				State rem = set.floor(new State(curr.l, 1 << 25, 0));
				set.remove(rem);
				ret[curr.index] = rem.index;
				if(--rem.left > 0) {
					set.add(rem);
				}
			}
			if(!win) {
				pw.println("NO");
				continue;
			}
			pw.println("YES");
			for(int out: ret) {
				pw.print(out + " ");
			}
			pw.println();
		}
		exitImmediately();
	}

	static class Person implements Comparable<Person> {
		public int l, r, index, time;
		public Person(int a, int b, int c, int d) {
			l=a;
			r=b;
			index = c;
			time = d;
		}
		public int compareTo(Person p) {
			if(r == p.r) return l - p.l;
			return r - p.r;
		}
	}

	static class State implements Comparable<State> {
		public int lowerBound, index, left;
		public State(int a, int b, int c) {
			lowerBound = a;
			index = b;
			left = c;
		}
		public String toString() {
			return lowerBound + " " + index + " " + left;
		}
		public int compareTo(State s) {
			if(lowerBound == s.lowerBound) {
				return index - s.index;
			}
			return lowerBound - s.lowerBound;
		}
	}

	static class Query implements Comparable<Query> {
		public int l, r, index;
		public Query(int a, int b, int c) {
			l=a;
			r=b;
			index=c;
		}
		public int compareTo(Query q) {
			if(r == q.r) return l - q.l;
			return r - q.r;
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