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
			String l = nextToken();
			String r = nextToken();
			int ques = 0;
			int ll = 0;
			for(int i = 0; i < l.length(); i++) {
				if(l.charAt(i) == '+') {
					ll++;
				}
				else {
					ll--;
				}
			}
			for(int i = 0; i < r.length(); i++) {
				if(r.charAt(i) == '?') {
					ques++;
				}
			}
			int denom = 1 << ques;
			int num = 0;
			if(ques == 0) {
				int rr = 0;
				for(int i = 0; i < r.length(); i++) {
					if(r.charAt(i) == '+') {
						rr++;
					}
					else {
						rr--;
					}
				}
				if(rr == ll) {
					num++;
				}
			}
			else {
				for(int mask = 0; mask < (1 << ques); mask++) {
					int curr = 0;
					int index = 0;
					for(int i = 0; i < r.length(); i++) {
						if(r.charAt(i) == '+') curr++;
						if(r.charAt(i) == '-') curr--;
						if(r.charAt(i) == '?') {
							if((mask&(1<<index)) == 0) curr--;
							else curr++;
							index++;
						}
					}
					if(curr == ll) {
						num++;
					}
				}
			}
			pw.println(1.0 * num / denom);
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