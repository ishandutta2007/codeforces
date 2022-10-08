import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Rect {
		long x1, y1, x2, y2;

		public Rect(long x1, long y1, long x2, long y2) {
			super();
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
		
		Rect isect(Rect o) {
			return new Rect(Math.max(x1, o.x1), Math.max(y1, o.y1), Math.min(x2, o.x2), Math.min(y2, o.y2));
		}
		
		Rect translate(long x, long y) {
			return new Rect(x1 + x, y1 + y, x2 + x, y2 + y);
		}
		
		long s() {
			return x1 < x2 && y1 < y2 ? (x2 - x1) * (y2 - y1) : 0;
		}
	}

	void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			int m = nextInt();
			int x1 = nextInt();
			int y1 = nextInt();
			int x2 = nextInt();
			int y2 = nextInt();
			Rect r = new Rect(0, 0, n, m);
			Rect r1 = r.translate(x1 - x2, y1 - y2).isect(r);
			Rect r2 = r.translate(x2 - x1, y2 - y1).isect(r);
//			System.out.println(r.s() + " " + r1.s() + " " + r2.s() + " " + r1.isect(r2).s());
			out.println(r.s() - r1.s() - r2.s() + r1.isect(r2).s());
		}
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