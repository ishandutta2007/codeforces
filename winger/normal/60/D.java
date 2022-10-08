import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private int[] p;
	private int[] r;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[10000001];
		Arrays.fill(b, -1);
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			if (b[a[i]] != -1) {
				throw new AssertionError();
			}
			b[a[i]] = i;
		}
		int ans = n;
		p = new int[n];
		r = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		for (int p = 1; p * p <= 10000000; ++p) {
			for (int q = p + 1; Math.max(q * q - p * p, 2 * p * q) <= 10000000; q += 2) {
				if (gcd(p, q) != 1) {
					continue;
				}
				int u = q * q - p * p;
				int v = 2 * p * q;
				int w = p * p + q * q;
				if (u < b.length && v < b.length && b[u] != -1 && b[v] != -1 && get(b[u]) != get(b[v])) {
					unite(b[u], b[v]);
					ans--;
				}
				if (u < b.length && w < b.length && b[u] != -1 && b[w] != -1 && get(b[u]) != get(b[w])) {
					unite(b[u], b[w]);
					ans--;
				}
				if (v < b.length && w < b.length && b[v] != -1 && b[w] != -1 && get(b[v]) != get(b[w])) {
					unite(b[v], b[w]);
					ans--;
				}
			}
		}
		out.println(ans);
	}

	private int get(int i) {
		if (p[i] != i) {
			p[i] = get(p[i]);
		}
		return p[i];
	}
	
	void unite(int i, int j) {
		i = p[i];
		j = p[j];
		if (r[i] < r[j]) {
			p[i] = j;
		} else {
			p[j] = i;
		}
		if (r[i] == r[j]) {
			++r[i];
		}
	}

	private int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
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