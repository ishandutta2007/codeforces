import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
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
			int a = readInt();
			int b = readInt();
			Set<String> x = new HashSet<String>();
			Set<String> y = new HashSet<String>();
			for(int i = 0; i < a; i++) {
				x.add(nextToken());
			}
			for(int i = 0; i < b; i++) {
				y.add(nextToken());
			}
			int aU = 0;
			int bU = 0;
			for(String out: x) {
				if(!y.contains(out)) {
					aU++;
				}
			}
			for(String out: y) {
				if(!x.contains(out)) {
					bU++;
				}
			}
			int c = a - aU;
			while(true) {
				// aa
				if(c > 0) {
					c--;
				}
				else if(aU > 0) {
					aU--;
				}
				else {
					pw.println("NO");
					break;
				}
				// bb
				if(c > 0) {
					c--;
				}
				else if(bU > 0) {
					bU--;
				}
				else {
					pw.println("YES");
					break;
				}
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