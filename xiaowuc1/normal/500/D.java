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
			int[] l = new int[n-1];
			int[] r = new int[n-1];
			int[] w = new int[n-1];
			LinkedList<Edge>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Edge>();
			}
			for(int i = 0; i < n-1; i++) {
				l[i] = readInt()-1;
				r[i] = readInt()-1;
				w[i] = readInt();
				edges[l[i]].add(new Edge(r[i], w[i]));
				edges[r[i]].add(new Edge(l[i], w[i]));
			}
			int[] d = new int[n];
			int[] c = new int[n];
			Arrays.fill(d, 1 << 25);
			d[0] = 0;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			LinkedList<Integer> rev = new LinkedList<Integer>();
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				rev.addFirst(curr);
				for(Edge out: edges[curr]) {
					if(d[out.d] == 1 << 25) {
						d[out.d] = 1 + d[curr];
						q.addLast(out.d);
					}
				}
			}
			while(!rev.isEmpty()) {
				int curr = rev.removeFirst();
				for(Edge out: edges[curr]) {
					if(d[out.d] > d[curr]) {
						c[curr] += 1 + c[out.d];
					}
				}
			}
			long total = choose3(n);
			double ret = 0;
			for(int i = 0; i < n; i++) {
				for(Edge out: edges[i]) {
					if(d[out.d] < d[i]) continue;
					int numBelow = c[out.d] + 1;
					int numOther = n - numBelow;
					long actual = total - choose3(numBelow) - choose3(numOther);
					ret += 2.0 * actual / total * out.w; 
				}
			}
			int qqq = readInt();
			while(qqq-- > 0) {
				int index = readInt()-1;
				int next = readInt();
				int dec = w[index] - next;
				w[index] = next;
				int parent, child;
				if(d[r[index]] > d[l[index]]) {
					parent = l[index];
					child = r[index];
				}
				else {
					child = l[index];
					parent = r[index];
				}
				int numBelow = c[child] + 1;
				int numOther = n - numBelow;
				long actual = total - choose3(numBelow) - choose3(numOther);
				ret -= 2.0 * actual / total * dec; 
				pw.println(ret);
			}
		}
		exitImmediately();
	}
	
	static class Edge {
		public int d,w;

		public Edge(int d, int w) {
			super();
			this.d = d;
			this.w = w;
		}
		
	}
	
	public static long choose3(long n) {
		return n*(n-1)*(n-2)/6;
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