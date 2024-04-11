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
			int exam = readInt();
			int[] start = new int[exam];
			int[] examDay = new int[exam];
			int[] left = new int[exam];
			for(int i = 0; i < exam; i++) {
				start[i] = readInt();
				examDay[i] = readInt();
				left[i] = readInt();
			}
			int[] ret = new int[n];
			boolean good = true;
			for(int i = 0; good && i < n; i++) {
				// look for exam
				int examIdx = -1;
				for(int a = 0; a < exam; a++) {
					if(examDay[a] == i+1) {
						examIdx = a;
						break;
					}
				}
				if(examIdx >= 0) {
					if(left[examIdx] > 0) {
						good = false;
					}
					ret[i] = exam+1;
					continue;
				}
				// among all that have started, find the one that ends the soonest
				int choice = -1;
				for(int a = 0; a < exam; a++) {
					// done
					if(left[a] == 0) continue;
					// cannot start
					if(start[a] > i+1) continue;
					if(choice == -1) {
						choice = a;
					}
					else {
						if(examDay[a] < examDay[choice]) {
							choice = a;
						}
					}
				}
				if(choice == -1) {
					ret[i] = 0;
				}
				else {
					ret[i] = choice+1;
					left[choice]--;
				}
			}
			if(!good) {
				pw.println(-1);
				continue;
			}
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out);
				sb.append(" ");
			}
			sb.deleteCharAt(sb.length()-1);
			pw.println(sb);
		}
		exitImmediately();
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