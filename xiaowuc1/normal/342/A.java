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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int a=0,b=0,c=0,d=0,e=0,f=0;
			for(int i = 0; i < n; i++) {
				int curr = readInt();
				switch(curr) {
				case 1:
					a++;
					break;
				case 2:
					b++;
					break;
				case 3:
					c++;
					break;
				case 4:
					d++;
					break;
				case 5:
					e++;
					break;
				case 6:
					f++;
					break;
				}
			}
			ArrayList<State> ret = new ArrayList<State>();
			for(int i = 0; i < n/3; i++) {
				if(d > 0) {
					if(a == 0 || b == 0) {
						break;
					}
					d--;
					a--;
					b--;
					ret.add(new State(1,2,4));
				}
				else if(f > 0) {
					if(a == 0) {
						break;
					}
					if(b == 0 && c == 0) {
						break;
					}
					if(c > 0) {
						a--;
						c--;
						f--;
						ret.add(new State(1,3,6));
					}
					else if(b > 0) {
						a--;
						b--;
						f--;
						ret.add(new State(1,2,6));
					}
				}
				else {
					break;
				}
			}
			if(ret.size() != n/3) {
				pw.println(-1);
			}
			else {
				for(State out: ret) {
					pw.println(out);
				}
			}
		}
		pw.close();
	}

	static class State {
		public int a,b,c;

		public State(int a, int b, int c) {
			super();
			this.a = a;
			this.b = b;
			this.c = c;
		}

		public String toString() {
			return a + " " + b + " " + c;
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