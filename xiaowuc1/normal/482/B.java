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
			int[] l = new int[m];
			int[] r = new int[m];
			int[] q = new int[m];
			int[][] bits = new int[30][n];
			for(int i = 0; i < m; i++) {
				l[i] = readInt()-1;
				r[i] = readInt()-1;
				q[i] = readInt();
				for(int a = 0; a < 30; a++) {
					if((q[i]&(1<<a)) == 0) continue;
					bits[a][l[i]]++;
					if(r[i] != n-1) {
						bits[a][r[i]+1]--;
					}
				}
			}
			int[][] prefix = new int[30][n+1];
			for(int a = 0; a < prefix.length; a++) {
				int curr = 0;
				for(int i = 0; i < bits[a].length; i++) {
					curr += bits[a][i];
					prefix[a][i+1] = prefix[a][i];
					if(curr > 0) {
						prefix[a][i+1]++;
					}
				}
			}
			boolean good = true;
			for(int i = 0; good && i < m; i++) {
				for(int a = 0; a < 30; a++) {
					if((q[i]&(1<<a)) != 0) continue;
					if(prefix[a][r[i]+1] - prefix[a][l[i]] == r[i] - l[i] + 1) {
						good = false;
						break;
					}
				}
			}
			if(!good) {
				pw.println("NO");
			}
			else {
				pw.println("YES");
				for(int i = 0; i < n; i++) {
					int num = 0;
					for(int a = 0; a < 30; a++) {
						if(prefix[a][i+1] != prefix[a][i]) {
							num |= 1 << a;
						}
					}
					pw.print(num + " ");
				}
				pw.println();
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