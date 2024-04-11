import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	int n;
	int r, c;

	void solve() throws Exception {
		n = nextInt();

		r = nextInt() - 1;
		c = nextInt() - 1;
		long count = nextLong();

		long left = -1, right = n * 2L;

		while (left < right - 1) {
			long mid = (left + right) / 2;

			if (getSq(n, r, c, mid) >= count) {
				right = mid;
			} else {
				left = mid;
			}
		}
		
//		for (int i = 0; i <= 10; i++) {
//			System.err.println(getSq(n, r, c, i));
//		}
		
		out.println(right);
	}
	
	long getSq(int n, int x, int y, long size) {
		long cur = (size + 1) * (size + 1) + size * size;
		
		cur -= get(x + size - (n - 1));
		cur -= get(y + size - (n - 1));
		cur -= get(-(x - size));
		cur -= get(-(y - size));
		
		cur += getCorner((x + 1) + (y + 1) - (size + 1));
		cur += getCorner((x + 1) + (n - y) - (size + 1));
		cur += getCorner((n - x) + (y + 1) - (size + 1));
		cur += getCorner((n - x) + (n - y) - (size + 1));
		
		return cur;
	}
	
	private long getCorner(long min) {
		if (min >= 0) {
			return 0;
		}
		min = -min;
		return min * (min + 1) / 2;
	}

	long get(long a) {
		if (a <= 0) {
			return 0;
		}
		return a * a;
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
		new B().run();
	}

}