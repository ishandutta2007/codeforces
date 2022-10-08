import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
//	private int[] p;

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt();
		int m = nextInt();
		int y = nextInt();
		int d = Math.abs(x - y); 
		long ans = 1;
		int comps = Math.max(0, Math.min(n, d - m - 1)) + Math.max(0, Math.min(m, d - n - 1));
		if (n + m >= d) {
			++comps;
		}
		comps += Math.max(0, n - d - m);
		comps += Math.max(0, m - d - n);
		ans += comps;
//		int comps2 = n + m;
//		p = new int[n + m];
//		for (int i = 0; i < n + m; ++i) {
//			p[i] = i;
//		}
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= m; ++j) {
//				if (i + j >= d && i <= j + d && j <= i + d && get(i - 1) != get(n + j - 1)) {
//					unite(i - 1, n + j - 1);
//					comps2--;
//				}
//			}
//		}
//		if (comps != comps2) {
//			throw new AssertionError();
//		}
//		long ans2 = 1 + comps2;
		for (int i = 1; i <= n; ++i) {
			int l = Math.max(d - i, i - d);
			int r = d + i;
			if (1 <= l && l <= m) {
				ans++;
			}
			if (1 <= r && r <= m && l != r) {
				ans++;
			}
			ans += 2 * Math.max(0, Math.min(r - 1, m) - Math.max(1, l + 1) + 1);
//			for (int j = 1; j <= m; ++j) {
//				if (d - i <= j && i - d <= j && j <= i + d) {
//					if (i + j == d || i == j + d || j == i + d) {
//						ans2++;
//					} else {
//						ans2 += 2;
//					}
//				}
//			}
		}
//		if (ans != ans2) {
//			throw new AssertionError(ans + " " + ans2);
//		}
		out.println(ans);
	}

//	private int get(int i) {
//		if (p[i] != i) {
//			p[i] = get(p[i]);
//		}
//		return p[i];
//	}
//	
//	void unite(int i, int j) {
//		i = get(i);
//		j = get(j);
//		p[i] = j;
//	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
//		Random rnd = new Random(42);
//		while (rnd != null) {
//			int n = rnd.nextInt(100) + 1;
//			int m = rnd.nextInt(100) + 1;
//			int x = rnd.nextInt(100);
//			int y = rnd.nextInt(100);
//			if (x == y) {
//				continue;
//			}
//			System.err.println(n + " " + x + " " + m + " " + y);
//			st = new StringTokenizer(n + " " + x + " " + m + " " + y);
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