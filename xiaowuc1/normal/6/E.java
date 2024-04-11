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

	static int[] list;
	
	static ArrayList<Integer>[][][][] ret;
	
	static int n, a, b;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			ArrayList<State> ret = new ArrayList<State>();
			int curr = 0;
			int[] list = new int[n];
			int k = readInt();
			int l = 0;
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				change(map, list[i], 1);
				while(map.lastKey() - map.firstKey() > k) {
					change(map, list[l++], -1);
				}
				if(i - l + 1 > curr) {
					ret = new ArrayList<State>();
					curr = i-l+1;
				}
				if(i-l+1 == curr) {
					ret.add(new State(l+1, i+1));
				}
			}
			pw.println(curr + " " + ret.size());
			for(State out: ret) {
				pw.println(out);
			}
		}	
		exitImmediately();
	}

	public static void change(Map<Integer, Integer> m, int k, int d) {
		if(!m.containsKey(k)) { 
			m.put(k, 0);
		}
		m.put(k, m.get(k) + d);
		if(m.get(k) == 0) {
			m.remove(k);
		}
	}
	
	static class State {
		public int a,b;

		public State(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}
		
		public String toString() {
			return a + " " + b;
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