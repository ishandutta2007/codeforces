import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static class Node implements Comparable<Node> {
		int id, val;

		public Node(int id, int val) {
			super();
			this.id = id;
			this.val = val;
		}

		@Override
		public int compareTo(Node o) {
			if (val == o.val) {
				return id - o.id;
			}
			return val - o.val;
		}
	}
	
	static class Event {
		public Event(Node node, boolean add) {
			super();
			this.node = node;
			this.add = add;
		}

		boolean add;
		
		Node node;
	}

	public void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; ++i) {
			a[nextInt() - 1] = i;
		}
		for (int i = 0; i < n; ++i) {
			b[nextInt() - 1] = i;
		}
		// | a[i] - (b[i] + t) % n |
		int[] d = new int[n];
		Arrays.fill(d, n);
		{
			List<Event>[] evs = new List[2 * n + 1];
			for (int i = 0; i < evs.length; ++i) {
				evs[i] = new ArrayList<Solution.Event>();
			}
			for (int i = 0; i < n; ++i) {
				int t = n + a[i] - b[i];
				int len = n - a[i];
				Node node = new Node(i, -t);
				evs[t].add(new Event(node, true));
				evs[t + len].add(new Event(node, false));
			}
			TreeSet<Node> nodes = new TreeSet<Solution.Node>();
			for (int i = 0; i <= 2 * n; ++i) {
				for (Event e : evs[i]) {
					if (e.add) {
						nodes.add(e.node);
					} else {
						nodes.remove(e.node);
					}
				}
				if (!nodes.isEmpty()) {
					d[i % n] = Math.min(d[i % n], i + nodes.first().val);
				}
			}
		}
		{
			List<Event>[] evs = new List[2 * n + 1];
			for (int i = 0; i < evs.length; ++i) {
				evs[i] = new ArrayList<Solution.Event>();
			}
			for (int i = 0; i < n; ++i) {
				int t = n + a[i] - b[i];
				int len = a[i] + 1;
				Node node = new Node(i, t);
				evs[t].add(new Event(node, true));
				evs[t - len].add(new Event(node, false));
			}
			TreeSet<Node> nodes = new TreeSet<Solution.Node>();
			for (int i = 2 * n; i >= 0; --i) {
				for (Event e : evs[i]) {
					if (e.add) {
						nodes.add(e.node);
					} else {
						nodes.remove(e.node);
					}
				}
				if (!nodes.isEmpty()) {
					d[i % n] = Math.min(d[i % n], -i + nodes.first().val);
				}
			}
		}
//		for (int i = 0; i < n; ++i) {
//			int v = n;
//			for (int j = 0; j < n; ++j) {
//				v = Math.min(v, Math.abs(a[j] - (b[j] + i) % n));
//			}
//			if (v != d[i]) {
//				throw new AssertionError();
//			}
//		}
		out.println(d[0]);
		for (int i = n - 1; i > 0; --i) {
			out.println(d[i]);
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
//		Random rnd = new Random();
//		while (rnd != null) {
//			StringBuilder sb = new StringBuilder();
//			int n = 5;
//			List<Integer> ans = new ArrayList<Integer>();
//			for (int i = 0; i < n; ++i) {
//				ans.add(i + 1);
//			}
//			sb.append(n + "\n");
//			Collections.shuffle(ans, rnd);
//			for (int i = 0; i < n; ++i) {
//				sb.append(ans.get(i) + " ");
//			}
//			sb.append("\n");
//			Collections.shuffle(ans, rnd);
//			for (int i = 0; i < n; ++i) {
//				sb.append(ans.get(i) + " ");
//			}
//			sb.append("\n");
//			eat(sb.toString());
//			solve();
//		}
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}