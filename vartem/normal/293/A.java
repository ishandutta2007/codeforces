import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;
	final String fileName = "A".toLowerCase();

	void solve() {
		int n = in.nextInt();
		String a = in.next();
		String b = in.next();
		int[][] count = new int[2][2];
		for (int i = 0; i < 2 * n; i++) {
			int x = a.charAt(i) - '0';
			int y = b.charAt(i) - '0';
			count[x][y]++;
		}
		
		int countA = 0, countB = 0;
		
		int[] t = new int[2 * n];
		int tmp = 0;
		for (int i = 0; i < count[1][1]; i++) {
			t[tmp++] = 3;
		}
		for (int i = 0; i < count[0][1]; i++) {
			t[tmp++] = 1;
		}
		for (int i = 0; i < count[1][0]; i++) {
			t[tmp++] = 2;
		}
		
		for (int i = 0; i < 2 * n; i++) {
			if (i % 2 == 0) {
				if (t[i] == 3 || t[i] == 2) {
					countA++;
				}
			} else {
				if (t[i] == 3 || t[i] == 1) {
					countB++;
				}
			}
		}
		
		if (countA == countB) {
			out.println("Draw");
		} else if (countA > countB) {
			out.println("First");
		} else {
			out.println("Second");
		}
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}