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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			boolean[][] dp = new boolean[10][2];
			for(int i = 0; i < 10; i++) {
				dp[i][1] = true;
			}
			while(n-- > 0) {
				String op = nextToken();
				int val = readInt();
				for(int i = 0; i < 10; i++) {
					if(op.equals("^")) {
						if((val&(1<<i)) != 0) {
							dp[i][0] ^= true;
							dp[i][1] ^= true;
						}
					}
					if(op.equals("&")) {
						if((val&(1<<i)) == 0) {
							dp[i][0] = false;
							dp[i][1] = false;
						}
					}
					if(op.equals("|")) {
						if((val&(1<<i)) != 0) {
							dp[i][0] = true;
							dp[i][1] = true;
						}
					}
				}
			}
			int flip = 0;
			int setfalse = 0;
			int settrue = 0;
			for(int i = 0; i < 10; i++) {
				if(dp[i][0] && dp[i][1]) {
					settrue |= 1 << i;
				}
				if(!dp[i][0] && !dp[i][1]) {
					setfalse |= 1 << i;
				}
				if(dp[i][0] && !dp[i][1]) {
					flip |= 1 << i;
				}
			}
			ArrayList<String> ret = new ArrayList<>();
			if(flip != 0) {
				ret.add("^ " + flip);
			}
			if(setfalse != 0) {
				ret.add("& " + (1023&(~setfalse)));
			}
			if(settrue != 0) {
				ret.add("| " + settrue);
			}
			pw.println(ret.size());
			for(String out: ret) {
				pw.println(out);
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}