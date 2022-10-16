import java.io.*;
import java.util.*;

public class Airport {

	class Pair implements Comparable<Pair> {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(Pair o) {
			if (this.x == o.x)
				return this.y - o.y;
			else
				return this.x - o.x;
		}
	}
	
	void solve() throws Exception {
		int n = nextInt();
		Pair[] a = new Pair[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Pair(nextInt(), i);
		}
		Arrays.sort(a);
		TreeSet<Integer> places = new TreeSet<Integer>();
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		places.add(a[0].y);
		for (int i = 1; i < n; i++) {
			Pair t = a[i];
			Integer g = places.last();
			if (g == null || g < t.y)
				ans[t.y] = -1;
			else
				ans[t.y] = g - t.y - 1;
			places.add(t.y);
		}
		for (int i = 0; i < n; i++)
			out.print(ans[i] + " ");
		
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
	final String filename = new String("Airport").toLowerCase();

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
		new Airport().run();
	}

}