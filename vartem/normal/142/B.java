import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	boolean[][] used;
	int[][] hit;

	boolean[][] best;
	int bestCnt;
	int n, m;

	int[] dx = new int[] { 2, 2, 1, 1, -1, -1, -2, -2 };
	int[] dy = new int[] { -1, 1, 2, -2, -2, 2, 1, -1 };

	void gen(int i, int j, int cnt) {
		if (i == n) {
			if (cnt > bestCnt) {
				best = new boolean[n][m];
				bestCnt = cnt;
				for (int k = 0; k < n; k++) {
					best[k] = used[k].clone();
				}
			}
			return;
		}

		if (hit[i][j] == 0) {
			for (int k = 0; k < 8; k++) {
				int cx = i + dx[k];
				int cy = j + dy[k];
				if (cx >= 0 && cx < n && cy >= 0 && cy < m) {
					hit[cx][cy]++;
				}
			}
			used[i][j] = true;
			gen(i + ((j + 1) / m), (j + 1) % m, cnt + 1);

			for (int k = 0; k < 8; k++) {
				int cx = i + dx[k];
				int cy = j + dy[k];
				if (cx >= 0 && cx < n && cy >= 0 && cy < m) {
					hit[cx][cy]--;
				}
			}
			used[i][j] = false;

		}
		gen(i + ((j + 1) / m), (j + 1) % m, cnt);
	}

	void solve(int n, int m) throws Exception {
		this.n = n;
		this.m = m;
//		used = new boolean[n][m];
//		hit = new int[n][m];
//		bestCnt = 0;
//		gen(0, 0, 0);
//		out.println(n + " " + m + " " + bestCnt);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (best[i][j]) {
//					out.print(1);
//				} else {
//					out.print(0);
//				}
//			}
//			out.println();
//		}

		if (n > m) {
			int temporary = n;
			n = m;
			m = temporary;
		}

		int res;
		if (n == 1) {
			res = m;
		} else if (n == 2) {
			int a = m / 4;
			int b = m % 4;
			res = 4 * a;
			if (b > 2)
				b = 2;
			res += 2 * b;
		} else {
			res = (n * m + 1) / 2;
		}

		out.println(res);
//		if (res != bestCnt) {
//			System.err.println(n + " " + m + " " + bestCnt + " " + res);
//		}
//
//		out.println();
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve(nextInt(), nextInt());

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
		new B().run();
	}

}