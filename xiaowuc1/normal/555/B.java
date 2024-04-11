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
			int n = readInt();
			int m = readInt();
			long[] l = new long[n];
			long[] r = new long[n];
			for(int i = 0; i < n; i++) {
				l[i] = readLong();
				r[i] = readLong();
			}
			LinkedList<Interval> intervalList = new LinkedList<Interval>();
			TreeSet<Interval> intervalTree = new TreeSet<Interval>(new RightComp());
			for(int i = 0; i < n-1; i++) {
				intervalList.add(new Interval(l[i+1] - r[i], r[i+1] - l[i], i));
			}
			Collections.sort(intervalList, new LeftComp());
			Bridge[] b = new Bridge[m];
			for(int i = 0; i < m; i++) {
				b[i] = new Bridge(i+1, readLong());
			}
			Arrays.sort(b);
			int[] ret = new int[n-1];
			int placed = 0;
			for(Bridge out: b) {
				while(!intervalList.isEmpty() && intervalList.peek().l <= out.length) {
					intervalTree.add(intervalList.removeFirst());
				}
				while(!intervalTree.isEmpty()) {
					if(intervalTree.last().r < out.length) {
						intervalTree.remove(intervalTree.last());
						continue;
					}
					placed++;
					Interval last = intervalTree.ceiling(new Interval(out.length, out.length, 0));
					ret[last.index] = out.index;
					intervalTree.remove(last);
					break;
				}
			}
			if(placed != n-1) {
				pw.println("No");
				continue;
			}
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out + " ");
			}
			sb.deleteCharAt(sb.length()-1);
			pw.println("Yes");
			pw.println(sb);
		}
		exitImmediately();
	}

	static class RightComp implements Comparator<Interval> {
		public int compare(Interval a, Interval b) {
			int ret = Long.compare(a.r, b.r);
			if(ret == 0) {
				ret = Long.compare(b.l, a.l);
			}
			if(ret == 0) {
				ret = a.index - b.index;
			}
			return ret;
		}
	}
	
	static class LeftComp implements Comparator<Interval> {
		public int compare(Interval a, Interval b) {
			return Long.compare(a.l, b.l);
		}
	}
	
	static class Interval {
		public long l, r;
		public int index;
		public Interval(long l, long r, int index) {
			super();
			this.l = l;
			this.r = r;
			this.index = index;
		}
		@Override
		public String toString() {
			return "Interval [l=" + l + ", r=" + r + ", index=" + index + "]";
		}
		
	}
	
	static class Bridge implements Comparable<Bridge> {
		public int index;
		public long length;

		public Bridge(int index, long length) {
			super();
			this.index = index;
			this.length = length;
		}
		public int compareTo(Bridge b) {
			return Long.compare(length, b.length);
		}
		@Override
		public String toString() {
			return "Bridge [index=" + index + ", length=" + length + "]";
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