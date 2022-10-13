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

	static final long FOURTEEN_MOD = 8904427322771L;
	static final long HASH = 3137;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			String s = nextToken();
			String start = nextToken();
			String end = nextToken();
			long[] hash = new long[s.length()+1];
			long[] pows = new long[s.length()+1];
			boolean[] canStart = new boolean[s.length()+1];
			boolean[] canEnd = new boolean[s.length()+1];
			pows[0] = 1;
			for(int i = 0; i < s.length(); i++) {
				pows[i+1] = mult(pows[i], HASH, FOURTEEN_MOD);
				hash[i+1] = mult(hash[i], HASH, FOURTEEN_MOD);
				hash[i+1] += s.charAt(i);
				hash[i+1] %= FOURTEEN_MOD;
			}
			for(int i = 0; i + start.length() <= s.length(); i++) {
				if(s.substring(i, i + start.length()).equals(start)) {
					canStart[i] = true;
				}
			}
			for(int i = end.length(); i <= s.length(); i++) {
				if(s.substring(i-end.length(), i).equals(end)) {
					canEnd[i] = true;
				}
			}
			int ret = 0;
			for(int len = Math.max(start.length(), end.length()); len <= s.length(); len++) {
				HashSet<Long> set = new HashSet<Long>();
				for(int i = 0; i + len <= s.length(); i++) {
					if(!canStart[i]) continue;
					if(!canEnd[i+len]) continue;
					long add = hash[i + len];
					add -= mult(hash[i], pows[len], FOURTEEN_MOD);
					add += FOURTEEN_MOD;
					add %= FOURTEEN_MOD;
					set.add(add);
				}
				ret += set.size();
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static final int SCALE = 10000;

	public static long mult(long a, long b, long MOD) {
		if(b == 0) return 0;
		if(b == 1) return a;
		long ans = (SCALE * mult(a, b / SCALE, MOD)) % MOD;
		ans += (a * (b%SCALE)) % MOD;
		return ans % MOD;
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