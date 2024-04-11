import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			State[] l = new State[n];
			for(int i = 0; i < n; i++) {
				String s = nextToken();
				int ss = 0;
				int hh = 0;
				for(int a = 0; a < s.length(); a++) {
					if(s.charAt(a) == 's') {
						ss++;
					}
					else {
						hh++;
					}
				}
				l[i] = new State(ss, hh, s);
			}
			Arrays.sort(l);
			long ret = 0;
			int ss = 0;
			for(State out: l) {
				for(int i = 0; i < out.sss.length(); i++) {
					if(out.sss.charAt(i) == 's') {
						ss++;
					}
					else {
						ret += ss;
					}
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int s, h;
		public String sss;
		public State(int ss, int hh, String ssss) {
			s = ss;
			h = hh;
			sss = ssss;
		}
		public int compareTo(State ss) {
			long less = s * (long)ss.h;
			long greater = ss.s * (long)h;
			if(less > greater) return -1;
			if(greater > less) return 1;
			return 0;
		}
	}
	
	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}