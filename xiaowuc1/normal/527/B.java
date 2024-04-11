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
		outer: for(int casenum = 1; casenum <= qq; casenum++) {
			int[][] grid = new int[26][26];
			for(int i = 0; i < grid.length; i++) {
				Arrays.fill(grid[i], -1);
			}
			nextToken();
			String a = nextToken();
			String b = nextToken();
			int ret = 0;
			for(int i = 0; i < a.length(); i++) {
				if(a.charAt(i) == b.charAt(i)) continue;
				ret++;
				grid[a.charAt(i) - 'a'][b.charAt(i) - 'a'] = i+1;
			}
			for(int x = 0; x < 26; x++) {
				for(int y = 0; y < 26; y++) {
					if(grid[x][y] > 0 && grid[y][x] > 0) {
						pw.println(ret-2);
						pw.println(grid[x][y] + " " + grid[y][x]);
						continue outer;
					}
				}
			}
			for(int x = 0; x < 26; x++) {
				for(int y = 0; y < 26; y++) {
					for(int z = 0; z < 26; z++) {
						if(grid[x][y] > 0 && grid[y][z] > 0) {
							pw.println(ret-1);
							pw.println(grid[x][y] + " " + grid[y][z]);
							continue outer;
						}
					}
				}
			}
			pw.println(ret);
			pw.println("-1 -1");
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