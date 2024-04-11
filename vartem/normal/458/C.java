import java.io.*;
import java.util.*;

public class C {

	public void solve() {
		int n = in.nextInt();

		int our = 0;

		Map<Integer, List<Citizen>> voters = new HashMap<>();

		List<Citizen> all = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			int a = in.nextInt(), b = in.nextInt();
			if (a == 0) {
				our++;
			} else {
				if (!voters.containsKey(a)) {
					voters.put(a, new ArrayList<Citizen>());
				}

				Citizen cur = new Citizen(b, a, i);
				voters.get(a).add(cur);
				all.add(cur);
			}
		}
		voters.put(Integer.MAX_VALUE, new ArrayList<Citizen>());
		Collections.sort(all);
		int[] pos = new int[n];
		SegmentTree tree = new SegmentTree(n);

		for (int i = 0; i < all.size(); i++) {
			pos[all.get(i).id] = i;
			tree.addValue(i, all.get(i).cost, 1);
		}

		int ans = Integer.MAX_VALUE;

		PriorityQueue<List<Citizen>> pq = new PriorityQueue<>(voters.size(),
				new Comparator<List<Citizen>>() {
					@Override
					public int compare(List<Citizen> o1, List<Citizen> o2) {
						return -Integer.compare(o1.size(), o2.size());
					}
				});

		for (int i : voters.keySet()) {
			List<Citizen> list = voters.get(i);
			Collections.sort(list);
			Collections.reverse(list);
			pq.add(list);
		}

		int curCost = 0;

		for (int toWin = n; toWin >= 1; toWin--) {
			while (pq.size() > 0 && pq.peek().size() >= toWin) {
				List<Citizen> list = pq.poll();

				Citizen bribe = list.get(list.size() - 1);
				tree.addValue(pos[bribe.id], -bribe.cost, -1);
				our++;
				curCost += bribe.cost;

				list.remove(list.size() - 1);
				pq.add(list);
			}

			int needMore = Math.max(0, toWin - our);
			if (needMore <= tree.count[0]) {
				int add = tree.getFirstK(needMore);
				ans = Math.min(ans, curCost + add);
			}
		}

		out.println(ans);
	}

	class SegmentTree {
		int size;
		int[] sum, count;

		public SegmentTree(int n) {
			this.size = n;
			sum = new int[4 * n];
			count = new int[4 * n];
		}

		void addValue(int pos, int toSum, int toCount) {
			addValue(0, size, pos, toSum, toCount, 0);
		}

		private void addValue(int left, int right, int pos, int toSum, int toCount, int i) {
			if (left + 1 == right) {
				sum[i] += toSum;
				count[i] += toCount;
				return;
			}

			int mid = (left + right) >> 1;

			if (pos < mid) {
				addValue(left, mid, pos, toSum, toCount, 2 * i + 1);
			} else {
				addValue(mid, right, pos, toSum, toCount, 2 * i + 2);
			}
			sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
			count[i] = count[2 * i + 1] + count[2 * i + 2];
		}

		int getFirstK(int k) {
			return getFirstK(0, size, k, 0);
		}

		private int getFirstK(int left, int right, int k, int i) {
			if (k == 0) {
				return 0;
			}
			if (left + 1 == right) {
				return sum[i];
			}
			int mid = (left + right) >> 1;
			if (count[2 * i + 1] <= k) {
				return sum[2 * i + 1] + getFirstK(mid, right, k - count[2 * i + 1], 2 * i + 2);
			} else {
				return getFirstK(left, mid, k, 2 * i + 1);
			}
		}
	}

	class Citizen implements Comparable<Citizen> {
		int cost, vote, id;

		public Citizen(int cost, int vote, int id) {
			super();
			this.cost = cost;
			this.vote = vote;
			this.id = id;
		}

		@Override
		public int compareTo(Citizen o) {
			return Integer.compare(cost, o.cost);
		}
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
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

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}