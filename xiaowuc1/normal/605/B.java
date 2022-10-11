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
			int m = readInt();
			Edge[] edges = new Edge[m];
			int[] l = new int[m];
			int[] r = new int[m];
			for(int i = 0; i < m; i++) {
				int w = readInt();
				int inc = readInt();
				edges[i] = new Edge(w, inc, i);
			}
			Arrays.sort(edges);
			int[] lastUsed = new int[n];
			for(int i = 0; i < n; i++) {
				lastUsed[i] = i+1;
			}
			int lastIn = 0;
			boolean bad = false;
			for(Edge out: edges) {
				if(out.include == 1) {
					l[out.index] = lastIn;
					r[out.index] = lastIn+1;
					lastIn++;
					continue;
				}
				boolean found = false;
				for(int i = 0; !found && i < lastIn; i++) {
					if(lastUsed[i] < lastIn) {
						l[out.index] = i;
						r[out.index] = ++lastUsed[i];
						found = true;
					}
				}
				if(!found) {
					bad = true;
					break;
				}
			}
			if(bad) {
				pw.println(-1);
				continue;
			}
			for(int i = 0; i < m; i++) {
				pw.println(++l[i]+" "+ ++r[i]);
			}
		}
		exitImmediately();
	}

	static class Edge implements Comparable<Edge> {
		public int w;
		public int include;
		public int index;
		public Edge(int w, int include, int index) {
			super();
			this.w = w;
			this.include = include;
			this.index = index;
		}
		public int compareTo(Edge e) {
			if(w != e.w) return w - e.w;
			return e.include - include;
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}