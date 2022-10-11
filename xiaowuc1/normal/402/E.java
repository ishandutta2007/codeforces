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

	static int ret;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			boolean[][] grid = new boolean[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					grid[i][j] = readInt() > 0;
				}
			}
			boolean[] seen = new boolean[n];
			boolean[] processed = new boolean[n];
			ret = -1;
			for(int i = 0; i < n && ret == -1; i++) {
				ret = dfs(i, grid, seen, processed);
			}
			if(ret == -1) {
				pw.println("NO");
				continue;
			}
			boolean[] now = new boolean[n];
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(ret);
			now[ret] = true;
			int see = 0;
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				see++;
				for(int i = 0; i < n; i++) {
					if(grid[curr][i] && !now[i]) {
						now[i] = true;
						q.add(i);
					}
				}
			}
			if(see != n) {
				pw.println("NO");
				continue;
			}
			Arrays.fill(now, false);
			q.clear();
			q.add(ret);
			now[ret] = true;
			see = 0;
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				see++;
				for(int i = 0; i < n; i++) {
					if(grid[i][curr] && !now[i]) {
						now[i] = true;
						q.add(i);
					}
				}
			}
			if(see != n) {
				pw.println("NO");
				continue;
			}
			pw.println("YES");
		}
		exitImmediately();
	}

	public static int dfs(int curr, boolean[][] g, boolean[] s, boolean[] p) {
		if(p[curr]) return -1;
		if(s[curr]) return curr;
		s[curr] = true;
		for(int j = 0; j < g[curr].length; j++) {
			if(g[curr][j]) {
				int a = dfs(j, g, s, p);
				if(a >= 0) return a;
			}
		}
		p[curr] = true;
		return -1;
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