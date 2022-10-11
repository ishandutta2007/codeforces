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

	static int[] l, r;
	static double ret;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			l = new int[n];
			r = new int[n];
			for(int i = 0; i < n; i++) {
				l[i] = readInt();
				r[i] = readInt();
			}
			ret = 0;
			for(int i = 1; i <= 10000; i++) {
				double p = prob(i, 0, 0, 0);;
				ret += i * p;
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static double prob(int goal, int index, int above, int equal) {
		if(index == l.length) return equal+above >= 2 && above <= 1 ? 1 : 0;
		if(above > 1) return 0;
		if(r[index] < goal) {
			return prob(goal, index+1, above, equal);
		}
		if(l[index] > goal) {
			return prob(goal, index+1, above+1, equal);
		}
		double ret = 0;
		ret += 1.0 / (r[index] - l[index] + 1) * prob(goal, index+1, above, equal+1);
		ret += 1.0 * (r[index] - goal) / (r[index] - l[index] + 1) * prob(goal, index+1, above+1, equal);
		ret += 1.0 * (goal - l[index]) / (r[index] - l[index] + 1) * prob(goal, index+1, above, equal);
		return ret;
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