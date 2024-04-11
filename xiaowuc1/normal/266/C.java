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

	static ArrayList<State> list;
	static ArrayList<String> ret;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			list = new ArrayList<State>();
			for(int i = 0; i < n-1; i++) {
				list.add(new State(readInt(), readInt()));
			}

			ret = new ArrayList<String>();
			for(int dimension = n; dimension > 1 && !list.isEmpty(); dimension--) {
				int[] amt = new int[dimension+1];
				for(State out: list) {
					amt[out.y]++;
				}
				for(int i = 1; i < dimension; i++) {
					if(amt[i] == 0) {
						swapCol(i, dimension);
						break;
					}
				}
				if(list.get(0).x < dimension) {
					swapRow(list.get(0).x, dimension);
				}
				for(int i = list.size()-1; i >= 0; i--) {
					if(list.get(i).x >= dimension || list.get(i).y >= dimension) {
						list.remove(i);
					}
				}
			}
			
			pw.println(ret.size());
			for(String out: ret) {
				pw.println(out);
			}
			
		}
		exitImmediately();
	}

	public static void swapRow(int a, int b) {
		ret.add("1 " + a + " " + b);
		for(State out: list) {
			if(out.x == a) out.x = b;
			else if(out.x == b) out.x = a;
		}
	}
	
	public static void swapCol(int a, int b) {
		ret.add("2 " + a + " " + b);
		for(State out: list) {
			if(out.y == a) out.y = b;
			else if(out.y == b) out.y = a;
		}
	}
	
	
	
	static class State {
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
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