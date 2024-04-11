import java.io.*;
import java.util.*;

public class Discount {

	final String filename = new String("Discount").toLowerCase();

	class Item implements Comparable<Item> {
		long cost;
		int t, id;

		public Item(long cost, int t, int id) {
			this.cost = cost;
			this.t = t;
			this.id = id;
		}

		@Override
		public int compareTo(Item o) {
			if (cost == o.cost) {
				return t - o.t;
			}
			return Long.signum(cost - o.cost);
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
		ArrayList<Item> pens = new ArrayList<Discount.Item>();
		ArrayList<Item> chairs = new ArrayList<Discount.Item>();
		Item[] items = new Item[n];
		for (int i = 0; i < n; i++) {
			Item cur = new Item(nextInt(), nextInt(), i + 1);
			items[i] = cur;
			if (cur.t == 1) {
				chairs.add(cur);
			} else {
				pens.add(cur);
			}
		}
		Collections.sort(pens);
		Collections.sort(chairs);

		ArrayList<Integer>[] ans = new ArrayList[k];
		for (int i = 0; i < k; i++) {
			ans[i] = new ArrayList<Integer>();
		}
		int m = chairs.size();
		if (chairs.size() < k) {
			
			for (int i = 0; i < m; i++) {
				ans[i].add(chairs.get(i).id);
			}
			int tmp = 0;
			for (int i = m; i < k - 1; i++) {
				ans[i].add(pens.get(tmp++).id);
			}

			for (int i = tmp; i < pens.size(); i++) {
				ans[k - 1].add(pens.get(i).id);
			}
		} else {
			boolean[] used = new boolean[n];
			ans[0].add(chairs.get(0).id);
			used[chairs.get(0).id - 1] = true;
			for (int i = 1; i < k; i++) {
				ans[i].add(chairs.get(m - i).id);
				used[chairs.get(m - i).id - 1] = true; 
			}
			
			for (Item e : pens) {
				ans[0].add(e.id);
			}

			for (Item e : chairs) {
				if (!used[e.id - 1]) {
					ans[0].add(e.id);
				}
			}
		}

		long sum = 0;
		for (int i = 0; i < k; i++) {
			long min = Integer.MAX_VALUE;
			boolean ok = false;
			for (Integer e : ans[i]) {
				if (items[e - 1].t == 1) {
					ok = true;
				}
				min = Math.min(min, items[e - 1].cost);
				sum += 2L * items[e - 1].cost;
			}

			if (ok) {
				sum -= min;
			}
		}

		double res = ((double) sum) / 2;
		out.printf(Locale.US, "%.1f\n", res);
		for (ArrayList<Integer> al : ans) {
			out.print(al.size() + " ");
			for (int i : al) {
				out.print(i + " ");
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
		new Discount().run();
	}

}