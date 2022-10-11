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
			int[] dist = new int[n];
			Arrays.fill(dist, 1 << 30);
			dist[0] = 0;
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<>();
			}
			for(int i = 1; i < n; i++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			LinkedList<Integer> q = new LinkedList<>();
			q.add(0);
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				for(int out: edges[curr]) {
					if(dist[out] > 1 + dist[curr]) {
						dist[out] = 1 + dist[curr];
						q.add(out);
					}
				}
			}
			long even = 0;
			long odd = 0;
			for(int out: dist) {
				if(out%2 == 1) even++;
				else odd++;
			}
			pw.println(even*odd-n+1);
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