import java.io.*;
import java.util.*;

public class MedianSum {

	class Treap {
		int x, y, num;
		long[] sum;
		Treap left;
		Treap right;

		public Treap(int x, int y) {
			this.x = x;
			this.y = y;
			this.num = 1;
			sum = new long[6];
			sum[1] = x;
		}
	}

	Treap merge(Treap a, Treap b) {
		if (a == null)
			return b;
		if (b == null)
			return a;
		Treap result = null;
		if (a.y < b.y) {
			result = merge(a.right, b);
			a.right = result;
			update(a);
			return a;
		} else {
			result = merge(a, b.left);
			b.left = result;
			update(b);
			return b;
		}
	}

	void update(Treap t) {
		if (t == null)
			return;
		t.sum = new long[6];
		t.num = 1;
		if (t.left != null) {
			if (t.left.sum != null)
				t.sum = t.left.sum.clone();
			t.num += t.left.num;
		}
		t.sum[(t.num) % 5] += t.x;
		if (t.right != null) {
			if (t.right.sum != null)
				for (int i = 0; i < 5; i++)
					t.sum[(t.num + i) % 5] += t.right.sum[i];
			t.num += t.right.num;
		}

	}

	Treap[] split(Treap a, int val) { // res[0] < val <= res[1]
		Treap[] result = null;
		if (a == null)
			return new Treap[] { null, null };
		if (a.x < val) {
			result = split(a.right, val);
			a.right = result[0];
			update(a);
			return new Treap[] { a, result[1] };
		} else {
			result = split(a.left, val);
			a.left = result[1];
			update(a);
			return new Treap[] { result[0], a };
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		Random rnd = new Random();
		Treap a = null;
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			if (s.equals("add")) {
				int x = nextInt();
				Treap[] r = split(a, x);
				Treap g = new Treap(x, rnd.nextInt());
				Treap r1 = merge(r[0], g);
				Treap r2 = merge(r1, r[1]);
				a = r2;
			} else if (s.equals("sum")) {
				if (a != null) 
					out.println(a.sum[3]);
				else
					out.println(0);
			} else {
				int x = nextInt();
				Treap[] r = split(a, x);
				Treap[] rn = split(r[1], x + 1);
				Treap r1 = merge(r[0], rn[1]);
				a = r1;
			}
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

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
	final String filename = new String("MedianSum").toLowerCase();

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
		new MedianSum().run();
	}

}