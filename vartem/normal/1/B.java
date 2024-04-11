import java.io.*;
import java.util.*;

public class B1 {

	int decode(String s) {
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			res = res * 26 + (int) (s.charAt(i) - 'A') + 1;
		}
		return res;
	}
	
	String encode(int x) {
		String res = "";
		while (x > 0) {
			char cur = (char) ((char)((x - 1) % 26) + 'A');
			res = cur + res;
			x = (x - 1) / 26;
		}
		return res;
	}
	
	void solve() throws Exception {
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			StringTokenizer s1 = new StringTokenizer(s, "RC");
			try {
				int x = Integer.parseInt(s1.nextToken());

				int y = Integer.parseInt(s1.nextToken());
				out.println(encode(y) + x);
			} catch (Exception e) {
				String res = "";
				int j = 0;
				while (Character.isUpperCase(s.charAt(j))) {
					res = res + s.charAt(j);
					j++;
				}
				out.println("R" + s.substring(j) + "C" + decode(res));
			}
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader(filename + ".in"));
			//			out = new PrintWriter(filename + ".out");

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
	final String filename = new String("B1").toLowerCase();

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
		new B1().run();
	}

}