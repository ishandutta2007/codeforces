import java.io.*;
import java.util.*;

public class c {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		solve(in, out);
		out.close();
	}

	static private class SegmentTree {
		private class Node {
			int left = 0, right = 0, ans = 0, size = 0;

			public Node(Node l, Node r) {
				ans = l.ans + r.ans;
				size = l.size + r.size;
				left = l.left;
				right = r.right;
				if(l.right + r.left == 2) {
					ans++;
				}
			}

			public Node(char c) {
				size = 1;
				ans = 0;
				left = right = c == '.' ? 1 : 0;
			}

			public Node() {}
		}

		private Node[] tree;
		private int n;

		public void init(String str) {
			n = str.length();
			tree = new Node[2 * n];
			for(int i = 0; i < n; i++) {
				tree[n + i] = new Node(str.charAt(i));
			}
			for(int i = n - 1; i > 0; i--) {
				tree[i] = new Node(tree[i + i], tree[i + i + 1]);
			}
		}

		public int qry(int l, int r) {
			Node left = new Node();
			Node right = new Node();
			for(l += n, r += n; l < r; l /= 2, r /= 2) {
				if(l % 2 == 1) left = new Node(left, tree[l++]);
				if(r % 2 == 1) right = new Node(tree[--r], right);
			}
			return (new Node(left, right)).ans;
		}

		public void upd(int on, char v) {
			on += n;
			tree[on] = new Node(v);
			for(on /= 2; on > 0; on /= 2) {
				tree[on] = new Node(tree[on + on], tree[on + on + 1]);
			}
		}
	}

	static private void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		SegmentTree tree = new SegmentTree();
		tree.init(in.next());
		for(int i = 0; i < m; i++) {
			int pos = in.nextInt();
			char c = in.next().charAt(0);
			tree.upd(pos - 1, c);
			out.println(tree.qry(0, n));
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}