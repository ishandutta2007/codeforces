import java.io.*;
import java.util.*;

public class Domino {

	void solve() throws Exception {
		int n = nextInt();
		char[][] a = new char[4][n];
		if (n % 2 == 1) {
			a[0][0] = 'x';
			a[1][0] = 'x';
			a[2][n - 1] = 'y';
			a[3][n - 1] = 'y';
			char c1 = 'a';
			char c2 = 'b';
			char c3 = 'c';
			char c4 = 'd';
			int d = 1;
			for (int i = 1; i < n; i += 2) {
				a[0][i] = c1;
				a[0][i + 1] = c1;
				a[1][i] = c2;
				a[1][i + 1] = c2;
				a[2][i - 1] = c3;
				a[2][i] = c3;
				a[3][i - 1] = c4;
				a[3][i] = c4;
				c1 = (char) (c1 + d * 4);
				c2 = (char) (c2 + d * 4);
				c3 = (char) (c3 + d * 4);
				c4 = (char) (c4 + d * 4);
				d = -d;
			}
		} else {
			a[2][0] = 'x';
			a[3][0] = 'x';
			a[2][n - 1] = 'y';
			a[3][n - 1] = 'y';
			char c1 = 'a';
			char c2 = 'b';
			char c3 = 'c';
			char c4 = 'd';
			int d = 1;
			for (int i = 0; i < n; i += 2) {
				a[0][i] = c1;
				a[0][i + 1] = c1;
				a[1][i] = c2;
				a[1][i + 1] = c2;
				c1 = (char) (c1 + d * 4);
				c2 = (char) (c2 + d * 4);
				c3 = (char) (c3 + d * 4);
				c4 = (char) (c4 + d * 4);
				d = -d;
			}
			d = 1;
			for (int i = 1; i + 1 < n; i += 2) {
				a[2][i + 1] = c3;
				a[2][i] = c3;
				a[3][i + 1] = c4;
				a[3][i] = c4;
				c1 = (char) (c1 + d * 4);
				c2 = (char) (c2 + d * 4);
				c3 = (char) (c3 + d * 4);
				c4 = (char) (c4 + d * 4);
				d = -d;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++)
				out.print(a[i][j]);
			out.println();
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

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
	final String filename = new String("Domino").toLowerCase();

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
		new Domino().run();
	}

}