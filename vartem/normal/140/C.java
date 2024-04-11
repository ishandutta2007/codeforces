import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	class Pair implements Comparable<Pair> {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return x + " " + y;
		}

		@Override
		public int compareTo(Pair arg0) {
			if (x == arg0.x) {
				return y - arg0.y;
			}
			return x - arg0.x;
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n];
		TreeSet<Pair> ts = new TreeSet<Pair>();
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			if (!hm.containsKey(a[i])) {
				hm.put(a[i], 0);
			}
			hm.put(a[i], hm.get(a[i]) + 1);
		}

		for (int g : hm.keySet()) {
			ts.add(new Pair(hm.get(g), g));
		}
		ArrayList<int[]> ans = new ArrayList<int[]>();

		if (true) {

			while (!ts.isEmpty()) {

				Pair max = ts.pollLast();
				Pair max2 = ts.pollLast();
				Pair max3 = ts.pollLast();

				if (max == null || max2 == null || max3 == null) {
					break;
				}

				int[] res = new int[] { max.y, max2.y, max3.y };
				Arrays.sort(res);
				ans.add(res);
				if (max.x - 1 > 0)
					ts.add(new Pair(max.x - 1, max.y));
				if (max2.x - 1 > 0) 
					ts.add(new Pair(max2.x - 1, max2.y));
				if (max3.x - 1 > 0) 
					ts.add(new Pair(max3.x - 1, max3.y));
			}

		} else {

			Arrays.sort(a);
			ArrayDeque<Integer> ones = new ArrayDeque<Integer>();
			ArrayDeque<Pair> pairs = new ArrayDeque<Pair>();

			for (int j = 0; j < n; j++) {
				if (!pairs.isEmpty() && pairs.peekFirst().y < a[j]) {
					Pair p = pairs.pollFirst();
					ans.add(new int[] { a[j], p.y, p.x });
				} else if (!ones.isEmpty() && ones.peekFirst() < a[j]) {
					Pair p = new Pair(ones.pollFirst(), a[j]);
					pairs.addLast(p);
				} else {
					ones.addFirst(a[j]);
				}
			}
		}

		out.println(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < 3; j++) {
				out.print(ans.get(i)[2 - j] + " ");
			}
			out.println();
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
		new C().run();
	}

}