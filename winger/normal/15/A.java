import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	static class House implements Comparable<House> {
		int x, a;

		@Override
		public int compareTo(House o) {
			return x - o.x;
		}

		public House(int x, int a) {
			this.x = x;
			this.a = a;
		}
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int t = nextInt();
		House[] hs = new House[n];
		for (int i = 0; i < n; ++i) {
			hs[i] = new House(nextInt(), nextInt());
		}
		Arrays.sort(hs);
		int ans = 2;
		for (int i = 0; i < n - 1; ++i) {
			if (hs[i].a + hs[i + 1].a + 2 * t < 2 * (hs[i + 1].x - hs[i].x)) {
				ans += 2;
			} else if (hs[i].a + hs[i + 1].a + 2 * t == 2 * (hs[i + 1].x - hs[i].x)) {
				ans++;
			}
		}
		out.println(ans);
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