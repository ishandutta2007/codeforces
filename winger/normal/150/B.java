
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	int[] p;

	int get(int i) {
		if (p[i] != i) {
			p[i] = get(p[i]);
		}
		return p[i];
	}
	
	public void solve() throws IOException {
		long mod = 1000000007;
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		p = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		for (int i = 0; i + k <= n; ++i) {
			for (int j = 0; j < k; ++j) {
				p[get(i + j)] = get(i + k - j - 1);
			}
		}
		long ans = 1;
		boolean[] col = new boolean[n];
		for (int i = 0; i < n; ++i) {
			if (!col[get(i)]) {
				col[get(i)] = true;
				ans = (ans * m) % mod;
			}
		}
		out.println(ans);
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}