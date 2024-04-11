import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	class SegmentTree {
		int[] tree;
		int[] vals;
		int size;
		public SegmentTree(int size) {
			tree = new int[4 * size];
			vals = new int[size];
			this.size = size;
			buildTree(0, size, 0);
		}
		
		private void buildTree(int left, int right, int i) {
			if (left  + 1 == right) {
				tree[i] = left;
				return;
			}
			int mid = (left + right) >> 1;
			buildTree(left, mid, 2 * i + 1);
			buildTree(mid, right, 2 * i + 2);
			update(i);
		}
		
		public void set(int pos, int val) {
			set(0, size, 0, pos, val);
		}
		
		private void set(int left, int right, int i, int pos, int val) {
			if (left + 1 == right) {
				vals[pos] = val;
				if (val == 0) {
					tree[i] = left;
				} else {
					tree[i] = -1;
				}
				return;
			}
			
			int mid = (left + right) >> 1;
			if (pos >= mid) {
				set(mid, right, 2 * i + 2, pos, val);
			} else {
				set(left, mid, 2 * i + 1, pos, val);
			}
			update(i);
		}
		
		void update(int v) {
			if (tree[2 * v + 1] != -1) {
				tree[v] = tree[2 * v + 1];
			} else {
				tree[v] = tree[2 * v + 2];
			}
		}
		
		int getMin(int l, int r) {
			return getMin(0, size, l, r, 0);
			
		}
		
		int getMin(int left, int right, int l, int r, int i) {
			if (l <= left && right <= r) {
				return tree[i];
			}
			if (r <= left || right <= l) {
				return -1;
			}
			int mid = (left + right) >> 1;
			int ans1 = getMin(left, mid, l, r, 2 * i + 1);
			int ans2 = getMin(mid, right, l, r, 2 * i + 2);
			if (ans1 != -1) {
				return ans1;
			}
			return ans2;
		}
	}
	
	void solve() throws Exception {
		int h = nextInt();
		int m = nextInt();
		int n = nextInt();
		Map<Integer, Integer> pos = new HashMap<Integer, Integer>();
		Map<Integer, Integer> prevHash = new HashMap<Integer, Integer>();
		long ans = 0;
		boolean[] used = new boolean[h];
		int[] posGlobal = new int[h];
		int[] posLocal = new int[h];
		List<SegmentTree> trees = new ArrayList<C.SegmentTree>();
		List<List<Integer>> seqs = new ArrayList<List<Integer>>();
		List<Integer> counts = new ArrayList<Integer>();
		for (int i = 0; i < h; i++) {
			if (!used[i]) {
				List<Integer> curSeq = new ArrayList<Integer>();
				int count = 0;
				int j = i;
				while (!used[j]) {
					used[j] = true;
					posGlobal[j] = i;
					posLocal[j] = count;
					curSeq.add(j);
					count++;
					j = (j + m) % h;
				}
				seqs.add(curSeq);
				trees.add(new SegmentTree(count));
				counts.add(count);
			}
		}
		
		for (int i = 0; i < n; i++) {
			char op = nextToken().charAt(0);
			int id = nextInt();
			if (op == '+') {
				int hash = nextInt();
				int pg = posGlobal[hash];
				int pl = posLocal[hash];
				SegmentTree st = trees.get(pg);
				int ans1 = st.getMin(pl, counts.get(pg));
				if (ans1 == -1) {
					ans1 = st.getMin(0, counts.get(pg));
					ans += (counts.get(pg) + (ans1 - pl));
				} else {
					ans += ans1 - pl;
				}
				st.set(ans1, 1);
				pos.put(id, ans1);
				prevHash.put(id, hash);
			} else {
				int hash = prevHash.get(id);
				int pg = posGlobal[hash];
				SegmentTree st = trees.get(pg);
				int prevPos = pos.get(id);
				st.set(prevPos, 0);
				pos.remove(id);
				prevHash.remove(id);
			}		
			System.err.println(ans);
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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