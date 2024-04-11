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
			final long ADD = -1;
			final long MULT = -2;
			final long DELIM = -3;
			ArrayList<Long> list = new ArrayList<Long>();
			list.add(1L);
			list.add(MULT);
			String s = nextToken();
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '+') {
					list.add(ADD);
				}
				else if(s.charAt(i) == '*') {
					list.add(MULT);
				}
				else {
					list.add((long)s.charAt(i) - '0');
				}
			}
			list.add(MULT);
			list.add(1L);
			long ret = 0;
			ArrayList<Integer> muls = new ArrayList<Integer>();
			for(int i = 1; i < list.size(); i += 2) {
				if(list.get(i) == MULT) {
					muls.add(i);
				}
			}
			for(int i = 0; i < muls.size(); i++) {
				for(int j = i+1; j < muls.size(); j++) {
					int from = muls.get(i)+1;
					int to = muls.get(j)-1;
					Stack<Long> stack = new Stack<Long>();
					for(int a = 0; a < list.size(); a += 2) {
						if(a == 0) {
							stack.push(list.get(a));
						}
						else if(a == from) {
							stack.push(DELIM);
							stack.push(list.get(a));
						}
						else if(list.get(a-1) == MULT) {
							stack.push(stack.pop() * list.get(a));
						}
						else {
							stack.push(list.get(a));
						}
						if(a == to) {
							long curr = 0;
							while(stack.peek() != DELIM) {
								curr += stack.pop();
							}
							stack.pop();
							stack.push(stack.pop() * curr);
						}
					}
					long curr = 0;
					for(long out: stack) {
						curr += out;
					}
					ret = Math.max(ret, curr);
				}
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