import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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

	static boolean[] can;
	
	static Set<State> seen;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			can = new boolean[11];
			String s = nextToken();
			for(int i = 1; i <= 10; i++) {
				can[i] = s.charAt(i-1) == '1';
			}
			seen = new HashSet<State>();
			int size = readInt();
			LinkedList<Integer> ans = null;
			for(int i = 1; i <= 10 && ans == null; i++) {
				if(can[i]) {
					LinkedList<Integer> curr = new LinkedList<Integer>();
					curr.add(i);
					if(dfs(i, 0, i, size-1, curr)) {
						ans = curr;
					}
				}
			}
			if(ans == null) {
				pw.println("NO");
			}
			else {
				pw.println("YES");
				StringBuilder sb = new StringBuilder();
				for(int out: ans) {
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
	}
	
	public static boolean dfs(int a, int b, int c, int left, LinkedList<Integer> curr) {
		if(left == 0) {
			return true;
		}
		if(!seen.add(new State(a,b,c))) return false;
		for(int i = 1; i <= 10; i++) {
			if(can[i] && i != c) {
				if(a > b && b+i > a) {
					curr.addLast(i);
					if(dfs(a,b+i,i,left-1,curr)) {
						return true;
					}
					curr.removeLast();
				}
				if(b > a && a+i > b) {
					curr.addLast(i);
					if(dfs(a+i,b,i,left-1,curr)) {
						return true;
					}
					curr.removeLast();
				}
			}
		}
		return false;
	}

	static class State {
		public int x,y,last;

		public State(int x, int y, int last) {
			super();
			this.x = x;
			this.y = y;
			this.last = last;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + last;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (last != other.last)
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}