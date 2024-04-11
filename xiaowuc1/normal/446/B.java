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

	static int[] rowSum, colSum;
	static int n, m, p;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			n = readInt();
			m = readInt();
			int k = readInt();
			p = readInt();
			rowSum = new int[n];
			colSum = new int[m];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					int curr = readInt();
					rowSum[i] += curr;
					colSum[j] += curr;
				}
			}
			PriorityQueue<RowState> qInc = new PriorityQueue<RowState>(n, new SortRowDecrease());
			for(int i = 0; i < n; i++) {
				qInc.add(new RowState(i, 0));
			}
			long[] aScore = new long[k+1];
			for(int a = 0; a < k; a++) {
				RowState now = qInc.poll();
				aScore[a+1] = aScore[a] + now.score();
				now.numAdd++;
				qInc.add(now);
			}
			long[] bScore = new long[k+1];
			PriorityQueue<ColState> colInc = new PriorityQueue<ColState>(n, new SortColDecrease());
			for(int i = 0; i < m; i++) {
				colInc.add(new ColState(i, 0));
			}
			for(int a = 0; a < k; a++) {
				ColState now = colInc.poll();
				bScore[a+1] = bScore[a] + now.score();
				now.numAdd++;
				colInc.add(now);
			}
			long ret = Long.MIN_VALUE;
			for(int i = 0; i <= k; i++) {
				ret = Math.max(ret, aScore[i] + bScore[k-i] - i*1L*(k-i)*1L*p);
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class SortRowDecrease implements Comparator<RowState> {
		public int compare(RowState a, RowState b) {
			return Long.compare(b.score(), a.score());
		}
	}
	
	static class SortRowIncrease implements Comparator<RowState> {
		public int compare(RowState a, RowState b) {
			return Long.compare(a.score(), b.score());
		}
	}
	
	static class SortColDecrease implements Comparator<ColState> {
		public int compare(ColState a, ColState b) {
			return Long.compare(b.score(), a.score());
		}
	}
	
	static class RowState {
		public int index, numAdd;
		public RowState(int a, int b) {
			index = a;
			numAdd = b;
		}
		public long score() {
			return rowSum[index] - m * numAdd * p;
		}
		public String toString() {
			return "Row " + index + " with " + numAdd;
		}
	}
	
	static class ColState {
		public int index, numAdd;
		public ColState(int a, int b) {
			index = a;
			numAdd = b;
		}
		public long score() {
			return colSum[index] - n * numAdd * p;
		}
		public String toString() {
			return "Col " + index + " with " + numAdd;
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