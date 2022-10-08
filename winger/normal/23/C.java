import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Box implements Comparable<Box> {
		int id;
		long a, b;
		
		Box(int id, long a, long b) {
			this.id = id;
			this.a = a;
			this.b = b;
		}

		public int compareTo(Box o) {
			return Long.signum(o.a - a);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		Box[] bs = new Box[2 * n - 1];
		long totala = 0L, totalb = 0L;
		for (int i = 0; i < 2 * n - 1; ++i) {
			bs[i] = new Box(i + 1, nextLong(), nextLong());
			totala += bs[i].a;
			totalb += bs[i].b;
		}
		Arrays.sort(bs);
		long sumbOdd = 0L;
		for (int i = 0; i < 2 * n - 1; i += 2) {
			sumbOdd += bs[i].b;
		}
		out.println("YES");
		if (2 * sumbOdd >= totalb) {
			for (int i = 0; i < 2 * n - 1; i += 2) {
				out.print(bs[i].id + " ");
			}
		} else {
			out.print(bs[0].id + " ");
			for (int i = 1; i < 2 * n - 1; i += 2) {
				out.print(bs[i].id + " ");
			}
		}
		out.println();
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			solve();
		}
		
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