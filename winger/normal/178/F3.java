import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	static int k;
	
	static class Node {
		int count;
		List<Node> nodes = new ArrayList<Node>();
		
		int[] din() {
			int[] ret = new int[Math.min(k, count) + 1];
			int c = 0;
			for (Node n : nodes) {
				int[] d = n.din();
				for (int i = Math.min(k, c); i >= 0; --i) {
					for (int j = 1; j < d.length && i + j <= k; ++j) {
						ret[i + j] = Math.max(ret[i + j], ret[i] + d[j]);
					}
				}
				c += n.count;
			}
			for (int i = c + 1; i < ret.length; ++i) {
				ret[i] = ret[i - 1];
			}
			for (int i = 0; i < ret.length; ++i) {
				ret[i] += i * (i - 1) / 2;
			}
			return ret;
		}
	}
	
	Node build(int l, int r, int level, String[] ar) {
		Node ret = new Node();
		ret.count = r - l;
		while (l < r && ar[l].length() == level) {
			++l;
		}
		while (l < r) {
			int t = l;
			while (t < r && ar[t].charAt(level) == ar[l].charAt(level)) {
				++t;
			}
			ret.nodes.add(build(l, t, level + 1, ar));
			l = t;
		}
		return ret;
	}

	public void solve() throws IOException {
		int n = nextInt();
		k = nextInt();
		String[] strs = new String[n];
		for (int i = 0; i < n; ++i) {
			strs[i] = next();
		}
		Arrays.sort(strs);
		Node root = build(0, n, 0, strs);
//		System.err.println(Arrays.toString(root.din()));
		out.println(root.din()[k] - k * (k - 1) / 2);
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}