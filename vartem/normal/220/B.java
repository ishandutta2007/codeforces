import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	class Query {
		int l, r, id;

		public Query(int l, int r, int id) {
			super();
			this.l = l;
			this.r = r;
			this.id = id;
		}

	}

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[n];
		int[] count = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			if (a[i] <= n) {
				count[a[i]]++;
			}
		}
		int[] l = new int[m], r = new int[m];
		for (int i = 0; i < m; i++) {
			l[i] = nextInt() - 1;
			r[i] = nextInt() - 1;
		}

		Set<Integer> in = new TreeSet<Integer>();
		for (int i = 1; i <= n; i++) {
			if (count[i] >= i) {
				in.add(i);
			}
		}
		int size = in.size();
		int[] num = new int[n + 1];
		Arrays.fill(num, -1);
		int tmp = 0;
		int[] numbers = new int[size];
		for (int i : in) {
			num[i] = tmp;
			numbers[tmp++] = i;
		}
		int[] ans = new int[m];

		int[] prefSum = new int[n];
		for (int cur = 0; cur < size; cur++) {
			Arrays.fill(prefSum, 0);
			int curNumber = numbers[cur];
			for (int i = 0; i < n; i++) {
				if (a[i] == curNumber) {
					prefSum[i]++;
				}
			}
			for (int j = 1; j < n; j++) {
				prefSum[j] += prefSum[j - 1];
			}

			for (int i = 0; i < m; i++) {
				int s = prefSum[r[i]];
				if (l[i] > 0) {
					s -= prefSum[l[i] - 1];
				}
				if (s == curNumber) {
					ans[i]++;
				}
			}
		}
		for (int i : ans) {
			out.println(i);
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
		new B().run();
	}

}