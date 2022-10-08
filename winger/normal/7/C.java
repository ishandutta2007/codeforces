import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		long a0 = nextLong();
		long b0 = nextLong();
		long c0 = nextLong();
		long a = Math.abs(a0);
		long b = Math.abs(b0);
		long a0a = 1, b0a = 0;
		long a0b = 0, b0b = 1;
		while (b != 0) {
			long q = a / b;
			a = a - q * b;
			a0a = a0a - q * a0b;
			b0a = b0a - q * b0b;
			long tmp = a;
			a = b;
			b = tmp;
			tmp = a0a;
			a0a = a0b;
			a0b = tmp;
			tmp = b0a;
			b0a = b0b;
			b0b = tmp;
		}
		if (c0 % a != 0) {
			out.println(-1);
			return;
		}
		if (a0 < 0) {
			a0a *= -1;
		}
		if (b0 < 0) {
			b0a *= -1;
		}
		a0a *= -c0 / a;
		b0a *= -c0 / a;
		out.println(a0a + " " + b0a);
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