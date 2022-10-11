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
			int m = readInt();
			int qqq = readInt();
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			while(m-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			boolean[] seen = new boolean[n];
			int[] dist = new int[n];
			Arrays.fill(dist, 1 << 25);
			parent = new int[n];
			size = new HashMap<Integer, Integer>();
			for(int i = 0; i < n; i++) {
				if(seen[i]) continue;
				LinkedList<Integer> q = new LinkedList<Integer>();
				seen[i] = true;
				q.add(i);
				int last = -1;
				ArrayList<Integer> ours = new ArrayList<Integer>();
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					ours.add(curr);
					last = curr;
					for(int out: edges[curr]) {
						if(!seen[out]) {
							seen[out] = true;
							q.add(out);
						}
					}
				}
				dist[last] = 0;
				q.add(last);
				int max = 0;
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					max = Math.max(max, dist[curr]);
					for(int out: edges[curr]) {
						if(dist[out] > 1 + dist[curr]) {
							dist[out] = 1 + dist[curr];
							q.add(out);
						}
					}
				}
				for(int out: ours) {
					parent[out] = i;
				}
				size.put(i, max);
			}
			while(qqq-- > 0) {
				int type = readInt();
				if(type == 2) {
					union(readInt()-1, readInt()-1);
				}
				else {
					pw.println(size.get(find(readInt()-1)));
				}
			}
		}
		exitImmediately();
	}

	static int[] parent;
	static HashMap<Integer, Integer> size;
	
	public static int find(int x) {
		if(parent[x] == x) return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}
	
	public static void union(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return;
		int xSize = size.get(x);
		int ySize = size.get(y);
		size.remove(x);
		size.remove(y);
		parent[x] = y;
		int next = Math.max(xSize, ySize);
		next = Math.max(next, (xSize+1)/2 + (ySize+1)/2 + 1);
		size.put(find(b), next);
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