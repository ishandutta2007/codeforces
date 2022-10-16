import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	int n;

	int get(int s, int[] posf, int[] pos) {
		int best = n;
		int bestTime = -1;
		int curPos = n;
		int curCard = -1;
		for (int i = 0; i < n; i++) {
			if (i == s)
				continue;

			if (curPos > pos[i]) {
				curCard = i;
				curPos = pos[i];
			}
			
			if (posf[curCard] < best) {
				best = posf[curCard];
				bestTime = i;
			}
		}
		return bestTime + 1;
	}

	void solve() throws Exception {
		n = nextInt();
		int[][] friends = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				friends[i][nextInt() - 1] = j;
			}
		}
		int[] pos = new int[n];
		for (int j = 0; j < n; j++) {
			pos[nextInt() - 1] = j;
		}

		for (int i = 0; i < n; i++) {
			out.print(get(i, friends[i], pos) + " ");
		}
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
		new B().run();
	}

}