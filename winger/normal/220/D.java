import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final long mod = 1000000007;

	long st(long x, long y) {
		return (x + mod - (y % mod)) % mod;
	}
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	public void solve() throws IOException {
		int w = nextInt();
		int h = nextInt();
		long ans = 0;
		for (int x1 = 0; x1 < 2; ++x1) {
		for (int y1 = 0; y1 < 2; ++y1) {
			for (int x2 = 0; x2 < 2; ++x2) {
			for (int y2 = 0; y2 < 2; ++y2) {
				for (int x3 = 0; x3 < 2; ++x3) {
				for (int y3 = 0; y3 < 2; ++y3) {
					if (((x1 + x2 + x3) * (y1 + y2 + y3) - (x1 * y1 + x2 * y2 + x3 * y3)) % 2 == 0) {
						long val = 1;
						val = (val * ((w + 2 - x1) / 2)) % mod;
						val = (val * ((w + 2 - x2) / 2)) % mod;
						val = (val * ((w + 2 - x3) / 2)) % mod;
						val = (val * ((h + 2 - y1) / 2)) % mod;
						val = (val * ((h + 2 - y2) / 2)) % mod;
						val = (val * ((h + 2 - y3) / 2)) % mod;
						ans = (ans + val) % mod;
					}
				}
				}
			}
			}
		}
		}
		long total = ((w + 1) * (h + 1)) % mod;
		ans = st(ans, total);
		ans = st(ans, total * (total - 1) * 3);
		for (int x = 0; x <= w; ++x) {
			for (int y = 0; y <= h; ++y) {
				if (gcd(x, y) != 1) {
					continue;
				}
				long st = 0;
				for (int u = 1; x * u <= w && y * u <= h; ++u) {
					for (int v = u + 1; x * v <= w && y * v <= h; ++v) {
						st += (w - x * v + 1) * (h - y * v + 1);
					}
				}
				st *= x == 0 || y == 0 ? 6 : 12;
				ans = st(ans, st);
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}