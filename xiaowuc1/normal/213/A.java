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

	static int[] list;
	static LinkedList<Integer>[] edges;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			list = new int[n];
			edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt()%3;
				edges[i] = new LinkedList<Integer>();
			}
			for(int i = 0; i < n; i++) {
				int curr = readInt();
				while(curr-- > 0) {
					int p = readInt();
					edges[--p].add(i);
				}
			}
			pw.println(Math.min(solve(0), Math.min(solve(1), solve(2))));
		}
		exitImmediately();
	}

	public static int solve(int curr) {
		int ret = 0;
		int[] parent = new int[edges.length];
		for(int i = 0; i < edges.length; i++) {
			for(int out: edges[i]) {
				parent[out]++;
			}
		}
		boolean[] processed = new boolean[edges.length];
		int done = 0;
		LinkedList<Integer> q = new LinkedList<Integer>();
		while(done < edges.length) {
			for(int i = 0; i < parent.length; i++) {
				if(parent[i] == 0 && list[i] == curr && !processed[i]) {
					processed[i] = true;
					q.add(i);
				}
			}
			while(!q.isEmpty()) {
				int now = q.removeFirst();
				done++;
				ret++;
				for(int out: edges[now]) {
					if(--parent[out] == 0 && list[out] == curr && !processed[out]) {
						processed[out] = true;
						q.add(out);
					}
				}
			}
			if(done == edges.length) break;
			ret++;
			curr++;
			curr %= 3;
		}
		return ret;
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