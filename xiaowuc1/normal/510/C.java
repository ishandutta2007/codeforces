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
			String[] list = new String[n];
			for(int i = 0; i < n; i++) {
				list[i] = nextToken();
			}
			boolean[][] grid = new boolean[26][26];
			boolean forceBad = false;
			for(int i = 0; i < n-1; i++) {
				if(list[i].startsWith(list[i+1])) {
					forceBad = true;
					continue;
				}
				if(!list[i+1].startsWith(list[i])) {
					int a = 0;
					while(list[i].charAt(a) == list[i+1].charAt(a)) {
						a++;
					}
					grid[list[i].charAt(a) - 'a'][list[i+1].charAt(a) - 'a'] = true;
				}
			}
			for(int k = 0; k < 26; k++) {
				for(int i = 0; i < 26; i++) {
					for(int j = 0; j < 26; j++) {
						grid[i][j] |= grid[i][k] && grid[k][j];
					}
				}
			}
			for(int i = 0; i < 26; i++) {
				if(grid[i][i]) {
					forceBad = true;
				}
			}
			boolean[] used = new boolean[26];
			StringBuilder sb = new StringBuilder();
			for(int qqq = 0; qqq < 26; qqq++) {
				for(int i = 0; i < 26; i++) {
					if(used[i]) continue;
					boolean can = true;
					for(int j = 0; j < 26; j++) {
						if(grid[j][i] && !used[j]) {
							can = false;
						}
					}
					if(can) {
						used[i] = true;
						sb.append((char)('a' + i));
					}
				}
			}
			if(sb.length() < 26 || forceBad) {
				pw.println("Impossible");
			}
			else {
				pw.println(sb);
			}
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