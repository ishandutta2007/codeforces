import java.io.*;
import java.util.*;

public class Jumps {

	final String filename = new String("Jumps").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		char[] a = (nextToken() + nextToken()).toCharArray();
		Queue<Integer> q = new ArrayDeque<Integer>();
		int[] dist = new int[2 * n];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[0] = 0;
		q.add(0);
		while (!q.isEmpty()) {
			int c = q.poll();
			int di = dist[c];
			if (di > c % n) {
				continue;
			}
			int pos = c % n;
			if (pos + k >= n) {
				out.println("YES");
				return;
			}
			if (pos > 0 && a[c - 1] != 'X') {
				if (dist[c - 1] == Integer.MAX_VALUE) {
					dist[c - 1] = di + 1;
					q.add(c - 1);
				}
			}
			if (pos < n - 1 && a[c + 1] != 'X') {
				if (dist[c + 1] == Integer.MAX_VALUE) {
					dist[c + 1] = di + 1;
					q.add(c + 1);
				}
			}
			if (pos + k < n) {
				int to = (c + k + n) % (2 * n);
				if (a[to] != 'X' && dist[to] == Integer.MAX_VALUE) {
					dist[to] = di + 1;
					q.add(to);
				}
			}
		}
		out.println("NO");
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
		new Jumps().run();
	}

}