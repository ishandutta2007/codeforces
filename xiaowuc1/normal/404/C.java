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
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int k = readInt();
			int[] dist = new int[n];
			LinkedList<Integer>[] vertices = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				dist[i] = readInt();
				vertices[i] = new LinkedList<Integer>();
			}
			for(int i = 0; i < n; i++) {
				vertices[dist[i]].add(i);
			}
			if(vertices[0].size() != 1) {
				pw.println(-1);
				continue;
			}
			LinkedList<Integer> q = new LinkedList<Integer>();
			ArrayList<State> ret = new ArrayList<State>();
			q.add(vertices[0].getFirst());
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				if(dist[curr] == n-1) continue;
				int temp = dist[curr] == 0 ? k : k-1;
				while(temp-- > 0 && !vertices[dist[curr]+1].isEmpty()) {
					ret.add(new State(curr+1, 1+vertices[dist[curr]+1].getFirst()));
					q.add(vertices[dist[curr]+1].removeFirst());
				}
			}
			if(ret.size() != n-1) {
				pw.println(-1);
				continue;
			}
			pw.println(ret.size());
			for(State out: ret) {
				pw.println(out);
			}
		}
		exitImmediately();
	}

	static class State {
		public int a,b;
		public State(int x, int y) {
			a=x;
			b=y;
		}
		public String toString() {
			return a + " " + b;
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