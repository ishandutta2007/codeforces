import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
//	here
//	893554688


	void solve() throws IOException {
		char[] b = next().toCharArray();
		char[] n = next().toCharArray();
		long c = nextLong();
		long bb = mod(b, c);
		long ans = (bb + c - 1) % c;
		ans = (ans * modPow(bb, dec(n), c)) % c;
		out.println(ans == 0 ? c : ans);
	}
	
	long modPow(long x, int pow, long mod) {
		long r = 1;
		while (pow > 0) {
			if (pow % 2 == 1) {
				r = (r * x) % mod;
			}
			pow /= 2;
			x = (x * x) % mod;
		}
		return r;
	}

	private long modPow(long x, char[] dec, long mod) {
		long r = 1;
		for (int i = dec.length - 1; i >= 0; --i) {
			r = (r * modPow(x, dec[i] - '0', mod)) % mod;
			x = modPow(x, 10, mod);
		}
		return r;
	}

	private char[] dec(char[] n) {
		for (int i = n.length - 1; i >= 0; --i) {
			if (n[i] == '0') {
				n[i] = '9';
			} else {
				n[i]--;
				break;
			}
		}
		return n;
	}

	private long mod(char[] b, long c) {
		long r = 0;
		for (int i = 0; i < b.length; ++i) {
			r = (r * 10 + b[i] - '0') % c;
		}
		return r;
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