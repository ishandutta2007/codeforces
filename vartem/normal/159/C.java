import java.io.*;
import java.util.*;

public class StringManipulation {

	final String filename = new String("StringManipulation").toLowerCase();

	static Random rnd;

	class Treap {
		Treap left, right;
		int x, y;
		int count;

		public Treap(int x) {
			this.x = x;
			this.y = rnd.nextInt();
			this.count = 1;
		}
	}

	int getSize(Treap t) {
		if (t == null) {
			return 0;
		}
		return t.count;
	}

	void update(Treap t) {
		t.count = getSize(t.left) + getSize(t.right) + 1;
	}

	Treap merge(Treap t1, Treap t2) {
		if (t1 == null) {
			return t2;
		}
		if (t2 == null) {
			return t1;
		}

		if (t1.y < t2.y) {
			Treap res = merge(t1.right, t2);
			t1.right = res;
			update(t1);
			return t1;
		} else {
			Treap res = merge(t1, t2.left);
			t2.left = res;
			update(t2);
			return t2;
		}
	}

	Treap[] split(Treap t, int key) {
		if (t == null) {
			return new Treap[] { null, null };
		}
		if (t.x < key) {
			Treap[] res = split(t.right, key);
			t.right = res[0];
			update(t);
			return new Treap[] { t, res[1] };
		} else {
			Treap[] res = split(t.left, key);
			t.left = res[1];
			update(t);
			return new Treap[] { res[0], t };
		}
	}

	Treap add(Treap t, int value) {
		return merge(t, new Treap(value));
	}

	Treap remove(Treap t, int value) {
		Treap[] split1 = split(t, value);
		Treap[] split2 = split(split1[1], value + 1);
		return merge(split1[0], split2[1]);
	}

	int getKth(Treap t, int k) {
		if (k == getSize(t.left) + 1) {
			return t.x;
		}
		if (k <= getSize(t.left)) {
			return getKth(t.left, k);
		} else {
			return getKth(t.right, k - getSize(t.left) - 1);
		}
	}

	void asList(Treap p, List<Integer> list) {
		if (p != null) {
			asList(p.left, list);
			list.add(p.x);
			asList(p.right, list);
		}
	}

	void solve() throws Exception {
		rnd = new Random();
		Treap[] a = new Treap[26];
		int k = nextInt();
		String s = nextToken();
		int n = s.length();
		ArrayList<Integer>[] occur = new ArrayList[26];
		for (int i = 0; i < 26; i++) {
			occur[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < n; i++) {
			int c = (int) (s.charAt(i) - 'a');
			for (int j = 0; j < k; j++) {
				occur[c].add(i + j * n);
			}
		}

		for (int i = 0; i < 26; i++) {
			Collections.sort(occur[i]);
			for (int j : occur[i]) {
				a[i] = add(a[i], j);
			}
		}

		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int p = nextInt();
			int c = (int) (nextToken().charAt(0) - 'a');
			a[c] = remove(a[c], getKth(a[c], p));
		}

		char[] result = new char[k * n];
		Arrays.fill(result, '0');
		for (int i = 0; i < 26; i++) {
			List<Integer> list = new ArrayList<Integer>();
			asList(a[i], list);
			for (int j : list) {
				result[j] = (char) (i + 'a');
			}
		}

		for (char c : result) {
			if (c != '0') {
				out.print(c);
			}
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
		new StringManipulation().run();
	}

}