import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		ArrayList<Integer> ps = new ArrayList<Integer>();
		boolean[] prime = new boolean[n + 1];
		Arrays.fill(prime, true);
		prime[0] = prime[1] = false;
		for (int i = 2; i <= n; ++i) {
			if (prime[i]) {
				ps.add(i);
				for (int j = 2 * i; j <= n; j += i) {
					prime[j] = false;
				}
			}
		}
		for (int i = 0; i < ps.size() - 1; ++i) {
			int t = ps.get(i) + ps.get(i + 1) + 1;
			if (t <= n && prime[t]) {
				--k;
			}
		}
//		System.out.println(k);
		out.println(k <= 0 ? "YES" : "NO");
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