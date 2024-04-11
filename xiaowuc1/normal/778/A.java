import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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
			String source = nextToken();
			String target = nextToken();
			int[] order = new int[source.length()];
			for(int i = 0; i < order.length; i++) {
				order[i] = readInt()-1;
			}
			int min = 0;
			int max = order.length;
			while(min != max) {
				int mid = (min+max+1)/2;
				boolean[] bad = new boolean[order.length];
				for(int i = 0; i < mid; i++) {
					bad[order[i]] = true;
				}
				int index = 0;
				for(int i = 0; i < source.length() && index < target.length(); i++) {
					if(!bad[i] && source.charAt(i) == target.charAt(index)) {
						index++;
					}
				}
				if(index == target.length()) {
					min = mid;
				}
				else {
					max = mid-1;
				}
			}
			pw.println(min);
		}
		pw.close();
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