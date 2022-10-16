import java.io.*;
import java.util.*;

public class C {
	final int INF = 1_000_000_000 + 1000;
	void solve() {
		int n = in.nextInt();
		k = in.nextInt();
		int[][] s = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				s[i][j] = in.nextInt();
			}
		}
		
		TreeSet<Node>[] sortedMin = new TreeSet[k];
		TreeSet<Node>[] sortedMax = new TreeSet[k];
		
		for (int i = 0; i < k; i++) {
			final int id = i;
			sortedMin[i] = new TreeSet<Node>((o1, o2) -> o1.min[id] - o2.min[id]);
			sortedMax[i] = new TreeSet<Node>((o1, o2) -> o1.max[id] - o2.max[id]);
		}
		
		Node NEG_INF = new Node();
		Arrays.fill(NEG_INF.min, -INF);
		Arrays.fill(NEG_INF.max, -INF);
		Node POS_INF = new Node();
		Arrays.fill(POS_INF.min, INF);
		Arrays.fill(POS_INF.max, INF);
		for (int i = 0; i < k; i++) {
			sortedMin[i].add(NEG_INF);
			sortedMin[i].add(POS_INF);
			sortedMax[i].add(NEG_INF);
			sortedMax[i].add(POS_INF);
		}
		
		TreeSet<Node> toDelete = new TreeSet<Node>((o1, o2) -> o1.min[0] - o2.min[0]);
		for (int i = 0; i < n; i++) {
			Node cur = new Node();
			System.arraycopy(s[i], 0, cur.min, 0, k);
			System.arraycopy(s[i], 0, cur.max, 0, k);
			Node min = NEG_INF, max = POS_INF;
			for (int j = 0; j < k; j++) {
				Node curMin = sortedMin[j].lower(cur);
				Node curMax = sortedMax[j].higher(cur);
				if (curMin.min[0] > min.min[0]) {
					min = curMin;
				}
				if (curMax.max[0] < max.max[0]) {
					max = curMax;
				}
			}
			
			Node union = new Node();
			union.size = 1;
			union.max = s[i].clone();
			union.min = s[i].clone();
			cur = max;
			toDelete.clear();
			while (cur != null && cur.min[0] <= min.min[0]) {
				toDelete.add(cur);
				union.size += cur.size;
				for (int j = 0; j < k; j++) {
					union.min[j] = Math.min(union.min[j], cur.min[j]);
					union.max[j] = Math.max(union.max[j], cur.max[j]);
				}
				cur = sortedMax[0].higher(cur);
			}
			for (int j = 0; j < k; j++) {
				sortedMax[j].removeAll(toDelete);
				sortedMin[j].removeAll(toDelete);
				sortedMax[j].add(union);
				sortedMin[j].add(union);
			}
			
			Node last = sortedMax[0].last();
			out.println(sortedMax[0].lower(last).size);
		}
	}
	int k;
	
	class Node {
		int[] min, max;
		int size;
		public Node() {
			this.min = new int[k];
			this.max = new int[k];
		}
		@Override
		public String toString() {
			return "Node [min=" + Arrays.toString(min) + ", max=" + Arrays.toString(max) + ", size=" + size + "]";
		}
		
		
	}
	
	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
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

		public boolean hasMoreTokens() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String line = br.readLine();
					if (line == null) {
						return false;
					}
					st = new StringTokenizer(line);
				} catch (IOException e) {
					return false;
				}
			}
			return true;
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

		public int[] nextIntArray(int length) {
			int[] array = new int[length];
			for (int i = 0; i < length; i++) {
				array[i] = nextInt();
			}
			return array;
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}