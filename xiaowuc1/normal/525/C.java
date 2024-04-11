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
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			int n = readInt();
			TreeSet<Integer> set = new TreeSet<Integer>();
			for(int i = 0; i < n; i++) {
				int val = readInt();
				if(set.add(val)) {
					map.put(val, 0);
				}
				map.put(val, 1 + map.get(val));
			}
			ArrayList<Integer> last = new ArrayList<Integer>();
			while(!set.isEmpty()) {
				int now = set.last();
				while(map.get(now) >= 2) {
					map.put(now, map.get(now) - 2);
					last.add(now);
				}
				if(map.containsKey(now-1) && map.get(now) > 0) {
					map.put(now-1, 1 + map.get(now-1));
				}
				set.remove(now);
			}
			long ret = 0;
			for(int i = 1; i < last.size(); i += 2) {
				ret += last.get(i) * 1L * last.get(i-1);
			}
			pw.println(ret);
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