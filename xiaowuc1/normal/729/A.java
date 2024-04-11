import java.io.*;
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
			nextToken();
			String s = nextToken();
			while(s.indexOf("ogogo") != -1) {
				s = s.substring(0, s.indexOf("ogogo")) + s.substring(s.indexOf("ogogo") + 2);
			}
			boolean[] bad = new boolean[s.length()];
			for(int i = 0; i + 2 < s.length(); i++) {
				if(s.charAt(i) == 'o' && s.charAt(i+1) == 'g' && s.charAt(i+2) == 'o') {
					bad[i] = true;
					bad[i+1] = true;
					bad[i+2] = true;
				}
			}
			for(int i = 0; i < s.length(); i++) {
				if(bad[i]) pw.print("*");
				else pw.print(s.charAt(i));
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