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
			int n = readInt();
			boolean[] a = new boolean[n];
			int[] l = new int[n];
			int[] r = new int[n];
			for(int i = 0; i < n; i++) {
				a[i] = nextToken().equals("F");
				l[i] = readInt();
				r[i] = readInt();
			}
			int ret = 0;
			for(int i = 1; i <= 366; i++) {
				int f = 0;
				int m = 0;
				for(int k = 0; k < n; k++) {
					if(i >= l[k] && i <= r[k]) {
						if(a[k]) f++;
						else m++;
					}
				}
				ret = Math.max(ret, 2 * Math.min(m, f));
			}
			pw.println(ret);
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