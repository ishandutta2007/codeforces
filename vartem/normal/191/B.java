import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	class Square implements Comparable<Square> {
		long cost;
		int id;

		public Square(long cost, int id) {
			super();
			this.cost = cost;
			this.id = id;
		}
		
		@Override
		public int compareTo(Square o) {
			return -Long.signum(cost - o.cost);
		}
	}
	
	void solve() throws Exception {
		int n = nextInt() - 1, k = nextInt();
		long b = nextLong();
		int[] cost=  new int[n];
		Square[] sq = new Square[n];
		for (int i = 0; i < n; i++) {
			cost[i] = nextInt();
			sq[i] = new Square(cost[i], i);
		}
		nextInt();
		
		Arrays.sort(sq);
		long[] sum = new long[n];
		for (int i = 0; i < n; i++) {
			sum[i] = sq[i].cost;
			if (i > 0) {
				sum[i] += sum[i - 1];
			}
		}
		int[] place = new int[n];
		for (int i = 0; i < n; i++) {
			place[sq[i].id] = i;
		}
		for (int i = 0; i < n; i++) {
			long s = 0;
			if (place[i] < k - 1) {
				s = sum[k - 1];
			} else {
				if (k > 1) {
					s = sum[k - 2];
				}
				s += cost[i];
			}
			if (s > b) {
				out.println(i + 1);
				return;
			}
		}
		out.println(n + 1);
	}

	void run() {
		try {
//			in = new BufferedReader(new FileReader(filename + ".in"));
//			out = new PrintWriter(filename + ".out");
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
		new B().run();
	}

}