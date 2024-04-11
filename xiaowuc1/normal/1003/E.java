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
			int diam = readInt();
			int maxDeg = readInt();
			if(diam >= n) {
				pw.println("NO");
				continue;
			}
			if(maxDeg == 1) {
				if(n == 2 && diam == 1) {
					pw.println("YES\n1 2");
				}
				else {
					pw.println("NO");
				}
				continue;
			}
			int minDiam = solve(n, maxDeg);
			if(diam < minDiam) {
				pw.println("NO");
				continue;
			}
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<>();
			}
			int nv = 1;
			{
				int rightD = diam/2;
				int leftD = diam - rightD;
				for(int i = 0; i < leftD; i++) {
					edges[i].add(nv++);
				}
				if(rightD > 0) {
					edges[0].add(nv);
					rightD--;
					while(rightD-- > 0) {
						edges[nv].add(nv+1);
						nv++;
					}
					nv++;
				}
			}
			LinkedList<Integer> q = new LinkedList<>();
			q.add(0);
			while(!q.isEmpty() && nv < n) {
				int curr = q.removeFirst();
				int maxAllowed = curr == 0 ? maxDeg : maxDeg-1;
				while(edges[curr].size() < maxAllowed && nv < n) {
					edges[curr].add(nv);
					nv++;
				}
				Collections.sort(edges[curr]);
				for(int out: edges[curr]) {
					q.add(out);
				}
			}
			pw.println("YES");
			for(int i = 0; i < n; i++) {
				for(int out: edges[i]) {
					pw.print(i+1);
					pw.print(" ");
					pw.println(out+1);
				}
			}
		}
		exitImmediately();
	}

	public static int solve(int n, int maxDeg) {
		LinkedList<Integer>[] edges = new LinkedList[n];
		for(int i = 0; i < n; i++) {
			edges[i] = new LinkedList<>();
		}
		int nextV = 1;
		for(int i = 0; i < n; i++) {
			int maxAllowed = i == 0 ? maxDeg : maxDeg-1;
			for(int a = 0; a < maxAllowed && nextV < n; a++) {
				edges[i].add(nextV);
				edges[nextV].add(i);
				nextV++;
			}
		}
		int[] dist = new int[n];
		Arrays.fill(dist, 1 << 25);
		dist[n-1] = 0;
		LinkedList<Integer> q = new LinkedList<>();
		q.add(n-1);
		int ret = 0;
		while(!q.isEmpty()) {
			int curr = q.removeFirst();
			for(int out: edges[curr]) {
				if(dist[out] > dist[curr] + 1) {
					dist[out] = dist[curr] + 1;
					q.add(out);
				}
			}
			ret = dist[curr];
		}
		return ret;
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(readToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(readToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readToken());
	}

	private static String readLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String readToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(readLine().trim());
		}
		return st.nextToken();
	}
}