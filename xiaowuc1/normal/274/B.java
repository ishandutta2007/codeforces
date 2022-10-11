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
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int a = 1; a < n; a++) {
				int x = readInt()-1;
				int y = readInt()-1;
				edges[x].add(y);
				edges[y].add(x);
			}
			long[] amt = new long[n];
			for(int i = 0; i < n; i++) {
				amt[i] = readLong();
			}
			Stack<Integer> order = new Stack<Integer>();
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			int[] dist = new int[n];
			Arrays.fill(dist, 1 << 25);
			dist[0] = 0;
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				order.push(curr);
				for(int out: edges[curr]) {
					if(dist[out] == 1 << 25) {
						dist[out] = 1 + dist[curr];
						q.add(out);
					}
				}
			}
			long[] numIncs = new long[n];
			long[] numDecs = new long[n];
			while(!order.isEmpty()) {
				int curr = order.pop();
				long maxInc = 0;
				long maxDec = 0;
				for(int out: edges[curr]) {
					if(dist[out] <= dist[curr]) continue;
					maxInc = Math.max(maxInc, numIncs[out]);
					maxDec = Math.max(maxDec, numDecs[out]);
				}
				long currNum = amt[curr] + maxInc - maxDec;
				if(currNum > 0) {
					maxDec += currNum;
				}
				else {
					maxInc -= currNum;
				}
				numIncs[curr] = maxInc;
				numDecs[curr] = maxDec;
			}
			pw.println(numIncs[0] + numDecs[0]);
		}
		exitImmediately();
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