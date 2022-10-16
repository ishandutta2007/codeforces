import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	boolean correct(String s) {
		if ((s.length() > 0 && s.charAt(0) != '0') || s.equals("0")) {
			BigInteger i = new BigInteger(s);
			if (i.compareTo(BigInteger.valueOf(1000 * 1000)) > 0) {
				return false;
			}
			return true;
		}
		return false;
	}
	
	void solve() throws Exception {
		String s = nextToken();
		int n = s.length();
		int best = -1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				String s1 = s.substring(0, i + 1);
				String s2 = s.substring(i + 1, j + 1);
				String s3 = s.substring(j + 1);
				if (correct(s1) && correct(s2) && correct(s3)) {
					best = Math.max(best, Integer.parseInt(s1) + Integer.parseInt(s2) + Integer.parseInt(s3));
				}
			}
		}
		out.println(best);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new A().run();
	}

}