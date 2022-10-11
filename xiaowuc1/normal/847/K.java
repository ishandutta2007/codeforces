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
			int n = readInt();
			int orig = readInt();
			int rep = readInt();
			int buy = readInt();
			int price = readInt();
			String[] lhs = new String[n];
			String[] rhs = new String[n];
			for(int i = 0; i < n; i++) {
				lhs[i] = nextToken();
				rhs[i] = nextToken();
			}
			Map<String, Integer> dp = new HashMap<String, Integer>();
			int ret = orig;
			dp.put(gen(lhs[0], rhs[0]), orig);
			for(int i = 1; i < n; i++) {
				String key = gen(lhs[i], rhs[i]);
				int inc = 0;
				if(lhs[i].equals(rhs[i-1])) {
					inc = rep;
				}
				else {
					inc = orig;
				}
				ret += inc;
				if(!dp.containsKey(key)) {
					dp.put(key, 0);
				}
				dp.put(key, dp.get(key) + inc);
			}
			ArrayList<Integer> act = new ArrayList<Integer>();
			for(String key: dp.keySet()) {
				act.add(dp.get(key));
			}
			Collections.sort(act);
			Collections.reverse(act);
			for(int i = 0; i < buy && i < act.size(); i++) {
				ret -= Math.max(0, act.get(i) - price);
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static String gen(String a, String b) {
		if(a.compareTo(b) < 0) {
			return a + " " + b;
		}
		else {
			return b + " " + a;
		}
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