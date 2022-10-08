import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		String s = next();
		int n = s.length();
		int[] p1 = palin1(s, n);
		int[] p2 = palin2(s, n);
		int[] d = new int[n];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			boolean palin = i % 2 == 0 ? p1[i / 2] == i / 2 + 1 : p2[i / 2] == i / 2 + 1;
			if (!palin) {
				continue;
			}
			d[i] = d[(i - 1) / 2] + 1;
			ans += d[i];
		}
//		System.out.println(Arrays.toString(d));
		out.println(ans);
	}

	private int[] palin1(String s, int n) {
		int[] p = new int[n];
		int l = 0, r = -1;
		for (int i = 0; i < n; ++i) {
			if (i <= r) {
				p[i] = Math.min(r - i + 1, p[l + r - i]);
			}
			while (i - p[i] >= 0 && i + p[i] < n && s.charAt(i - p[i]) == s.charAt(i + p[i])) {
				++p[i];
			}
			if (i + p[i] - 1 > r) {
				l = i - p[i] + 1;
				r = i + p[i] - 1;
			}
		}
		return p;
	}

	private int[] palin2(String s, int n) {
		int[] p = new int[n - 1];
		int l = 0, r = -1;
		for (int i = 0; i < n - 1; ++i) {
			if (i < r) {
				p[i] = Math.min(r - i, p[l + r - i - 1]);
			}
			while (i - p[i] >= 0 && i + p[i] + 1 < n && s.charAt(i - p[i]) == s.charAt(i + p[i] + 1)) {
				++p[i];
			}
			if (i + p[i] - 1 > r) {
				l = i - p[i] + 1;
				r = i + p[i];
			}
		}
		return p;
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