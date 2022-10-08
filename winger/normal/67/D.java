import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		if (n == 0) {
			throw new AssertionError();
		}
		int[] a = new int[n];
		Arrays.fill(a, -1);
		int[] le = new int[n];
		int[] ri = new int[n];
		for (int i = 0; i < n; ++i) {
			le[nextInt() - 1] = i;
		}
		for (int i = 0; i < n; ++i) {
			ri[nextInt() - 1] = i;
		}
		for (int i = 0; i < n; ++i) {
			int u = le[i];
			int v = ri[i];
			if (a[u] != -1) {
				throw new AssertionError();
			}
			a[u] = v;
		}
		int[] last = new int[n + 1];
		Arrays.fill(last, -1);
		last[0] = n;
		for (int i : a) {
			int l = 0, r = n + 1;
			while (l < r - 1) {
				int mid = (l + r) / 2;
				if (last[mid] > i) {
					l = mid;
				} else {
					r = mid;
				}
			}
			last[r] = i;
		}
		int ans = 0;
		while (ans < n && last[ans + 1] != -1) {
			ans++;
		}
		out.println(ans);
//		int ans2 = 0;
//		int[] d = new int[n];
//		for (int i = 0; i < n; ++i) {
//			d[i] = 1;
//			for (int j = 0; j < i; ++j) {
//				if (a[j] > a[i]) {
//					d[i] = Math.max(d[i], d[j] + 1);
//				}
//			}
//			ans2 = Math.max(ans2, d[i]);
//		}
//		if (ans != ans2) {
//			throw new AssertionError();
//		}
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
//		Random rnd = new Random();
//		while (rnd != null) {
//			int n = 7;
//			ArrayList<Integer> a = new ArrayList<Integer>();
//			for (int i = 0; i < n; ++i) {
//				a.add(i + 1);
//			}
//			StringBuilder sb = new StringBuilder();
//			sb.append(n + "\n");
//			Collections.shuffle(a, rnd);
//			for (int i : a) {
//				sb.append(i + " ");
//			}
//			Collections.shuffle(a, rnd);
//			for (int i : a) {
//				sb.append(i + " ");
//			}
//			eat(sb.toString());
//			solve();
//		}
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}