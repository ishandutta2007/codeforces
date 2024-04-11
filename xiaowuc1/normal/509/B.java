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
			int[] list = new int[n];
			ArrayList<Integer>[] ret = new ArrayList[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				ret[i] = new ArrayList<Integer>();
			}
			for(int color = 1; color <= k; color++) {
				int max = 0;
				for(int out: list) {
					max = Math.max(max, out);
				}
				if(max == 0) break;
				for(int a = 0; a < n; a++) {
					if(list[a] == max) {
						list[a]--;
						ret[a].add(color);
					}
				}
			}
			Arrays.sort(list);
			if(list[0] != list[n-1]) {
				pw.println("NO");
				continue;
			}
			pw.println("YES");
			for(int i = 0; i < n; i++) {
				StringBuilder sb = new StringBuilder();
				for(int out: ret[i]) {
					sb.append(out + " ");
				}
				while(list[i]-- > 0) {
					sb.append("1 ");
				}
				pw.println(sb.toString().trim());
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