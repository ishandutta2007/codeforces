import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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
			nextToken();
			nextToken();
			String a = nextToken();
			String b = nextToken();
			ArrayList<Integer> ret = new ArrayList<Integer>();
			for(int qqq = 0; qqq < 10000; qqq++) {
				ret.add(qqq);
			}
			for(int start = 0; start <= b.length() - a.length(); start++) {
				ArrayList<Integer> cand = new ArrayList<Integer>();
				for(int i = 0; i < a.length(); i++) {
					if(a.charAt(i) != b.charAt(i+start)) {
						cand.add(i+1);
					}
				}
				if(cand.size() < ret.size()) {
					ret = cand;
				}
			}
			pw.println(ret.size());
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
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