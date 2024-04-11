import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			TreeMap<Integer, Integer> map = new TreeMap<>();
			int n = readInt();
			while(n-- > 0) {
				int k = readInt();
				change(map, k, 1);
			}
			long ret = 0;
			while(map.lastKey() - map.firstKey() > 1) {
				int low = Math.min(map.get(map.firstKey()), map.get(map.lastKey()));
				if(map.get(map.firstKey()) == low) {
					change(map, map.firstKey()+1, low);
					change(map, map.firstKey(), -low);
					change(map, map.lastKey()-1, low);
					change(map, map.lastKey(), -low);
					ret += low;
				}
				else {
					change(map, map.firstKey()+1, low);
					change(map, map.firstKey(), -low);
					change(map, map.lastKey()-1, low);
					change(map, map.lastKey(), -low);
					ret += low;
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static void change(Map<Integer, Integer> m, int k, int d) {
		if(!m.containsKey(k)) m.put(k, 0);
		m.put(k, m.get(k) + d);
		if(m.get(k) == 0) m.remove(k);
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