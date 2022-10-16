import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n];
		for (int i =0 ; i < n; i++) {
			a[i] = nextInt();
		}
		int[] b = a.clone();
		Arrays.sort(b);
		for (int i = 0; i < n; i++) {
			a[i] = Arrays.binarySearch(b, a[i]);
		}
		int[] count = new int[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			count[a[i]]++;
			ans = Math.max(ans, count[a[i]]);
		}
		
		int[] next = new int[n], prev = new int[n];
		int[] first = new int[n];
		int[] cur = new int[n];
		Arrays.fill(first, -1);
		Arrays.fill(cur, -1);
		for (int i = 0; i < n; i++) {
			prev[i] = cur[a[i]];
			cur[a[i]] = i;
			if (first[a[i]] == -1) {
				first[a[i]] = i;
			}
		}
		Arrays.fill(cur, n);
		for (int i = n - 1; i >= 0; i--) {
			next[i] = cur[a[i]];
			cur[a[i]] = i;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				int x = first[i], y = first[j];
				if (x == -1 || y == -1) {
					continue;
				}
				
				int res = 1;
				while (x < n && y < n) {
					res++;
					if (x < y) {
						while (x < y) {
							x = next[x];
						}
					} else {
						while (y < x) {
							y = next[y];
						}
					}
				}
				ans = Math.max(res, ans);
			}
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
		new A().run();
	}

}