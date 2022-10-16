import java.io.*;
import java.util.*;

public class Markers {

	final String filename = new String("Markers").toLowerCase();

	class Pair implements Comparable<Pair> {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(Pair o) {
			if (y != o.y) {
				return y - o.y;
			}
			return x - o.x;
		}
	}
	
	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[1000][1000], b = new int[1000][1000];
		for (int i = 0; i < n; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			a[x][y]++;
		}
		
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			b[x][y]++;
		}
		
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				int toAdd = Math.min(a[i][j], b[i][j]);
				a[i][j] -= toAdd;
				b[i][j] -= toAdd;
				ans2 += toAdd;
				ans1 += toAdd;
			}
		}
		
		for (int j = 0; j < 1000; j++) {
			int sum1 = 0, sum2 = 0;
			for (int i = 0; i < 1000; i++) {
				sum1 += a[i][j];
				sum2 += b[i][j];
			}
			ans1 += Math.min(sum1, sum2);
		}
		
		out.println(ans1 + " " + ans2);
	}

	void run() {
		try {
			// in = new BufferedReader(new FileReader(filename + ".in"));
			// out = new PrintWriter(filename + ".out");
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
		new Markers().run();
	}

}