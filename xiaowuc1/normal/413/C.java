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
			int n = readInt();
			int m = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			Set<Integer> set = new HashSet<Integer>();
			while(m-- > 0) {
				set.add(readInt()-1);
			}
			ArrayList<Integer> doubles = new ArrayList<Integer>();
			long sum = 0;
			long ret = 0;
			for(int i = 0; i < n; i++) {
				if(set.contains(i)) {
					doubles.add(list[i]);
				}
				else {
					sum += list[i];
				}
			}
			Collections.sort(doubles);
			for(int tryDouble = 0; tryDouble <= doubles.size(); tryDouble++) {
				long curr = sum;
				for(int a = doubles.size()-1; a >= tryDouble; a--) {
					curr += doubles.get(a);
				}
				for(int a = 0; a < tryDouble; a++) {
					if(doubles.get(a) <= curr) {
						curr *= 2;
					}
					else {
						curr += doubles.get(a);
					}
				}
				ret = Math.max(ret, curr);
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