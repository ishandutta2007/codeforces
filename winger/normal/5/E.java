import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int max = -1, max2 = -1;
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			if (a[i] > max) {
				max2 = max;
				max = a[i];
			} else if (a[i] > max2) {
				max2 = a[i];
			}
		}
		long maxes = 0, maxes2 = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == max) {
				maxes++;
			}
			if (a[i] == max2) {
				maxes2++;
			}
		}
		long ans = solve(a);
		if (maxes > 1) {
			ans -= maxes * (maxes - 1) / 2;
		} else {
			ans -= maxes2;
		}
		out.println(ans);
	}

	private long solve(int[] a) {
		int n = a.length;
		long ans = 0;
		int[] q = new int[2 * n];
		boolean[] f = new boolean[2 * n];
		int s = 0, e = 0;
		for (int i = 0; i < n; ++i) {
			while (s < e && a[i] > a[q[e - 1]]) {
				e--;
			}
			q[e] = i;
			f[e] = true;
			e++;
		}
		for (int i = 0; i < n; ++i) {
			while (s < e && q[s] <= i && f[s]) {
				s++;
			}
			int l = s;
			int r = e;
			while (l < r - 1) {
				int mid = (l + r) / 2;
				if (a[q[mid]] > a[i]) {
					l = mid;
				} else {
					r = mid;
				}
			}
			ans += e - l;
			while (s < e && a[i] > a[q[e - 1]]) {
				e--;
			}
			q[e] = i;
			f[e] = false;
			e++;
		}
		return ans;
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