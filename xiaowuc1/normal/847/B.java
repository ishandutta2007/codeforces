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
			int n = readInt();
			ArrayList<ArrayList<Integer>> l = new ArrayList<ArrayList<Integer>>();
			while(n-- > 0) {
				int curr = readInt();
				int min = 0;
				int max = l.size();
				while(min != max) {
					int mid = (min+max)/2;
					ArrayList<Integer> x = l.get(mid);
					if(x.get(x.size()-1) < curr) {
						max = mid;
					}
					else {
						min = mid+1;
					}
				}
				if(min == l.size()) {
					l.add(new ArrayList<Integer>());
				}
				l.get(min).add(curr);
			}
			for(ArrayList<Integer> out: l) {
				for(int i = 0; i < out.size()-1; i++) {
					pw.print(out.get(i));
					pw.print(" ");
				}
				pw.println(out.get(out.size()-1));
			}
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