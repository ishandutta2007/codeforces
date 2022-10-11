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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt()-1;
			long have = readLong(); nextToken();
			State[] s = new State[n];
			for(int i = 0; i < n; i++) {
				s[i] = new State(readLong(), readLong());
			}
			Arrays.sort(s, new BalloonSorter());
			TreeMap<Long, Integer> diff = new TreeMap<>();
			int ret = n+1;
			int pres = 0;
			for(int i = 0; i < n && ret > 1; ) {
				while(have >= s[i].b && ret > 1) {
					ret = Math.min(ret, pres+1);
					if(pres == 0) {
						break;
					}
					else {
						long amt = diff.firstKey();
						if(amt > have) {
							break;
						}
						have -= amt;
						pres--;
						if(diff.get(amt) == 1) diff.remove(amt);
						else diff.put(amt, diff.get(amt)-1);
					}
				}
				int j = i;
				while(j < n && s[i].b == s[j].b) {
					long curr = s[j].w - s[j].b + 1;
					diff.put(curr, diff.getOrDefault(curr, 0) + 1);
					pres++;
					j++;
				}
				i = j;
			}
			while(ret > 1) {
				ret = Math.min(ret, pres+1);
				if(pres == 0) {
					break;
				}
				else {
					long amt = diff.firstKey();
					if(amt > have) {
						break;
					}
					have -= amt;
					pres--;
					if(diff.get(amt) == 1) diff.remove(amt);
					else diff.put(amt, diff.get(amt)-1);
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class BalloonSorter implements Comparator<State> { 
		public int compare(State a, State b) {
			return Long.compare(b.b, a.b);
		}
	}

	static class State {
		public long b, w;

		public State(long b, long w) {
			super();
			this.b = b;
			this.w = w;
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