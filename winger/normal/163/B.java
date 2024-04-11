import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static class Lemming implements Comparable<Lemming> {
		long m, v;
		int id;
		
		Lemming(long m, long v, int id) {
			this.m = m;
			this.v = v;
			this.id = id;
		}

		@Override
		public int compareTo(Lemming o) {
			if (m == o.m) {
				return Long.signum(v - o.v);
			}
			return Long.signum(m - o.m);
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		long h = nextInt();
		int[] ms = new int[n];
		int[] vs = new int[n];
		for (int i = 0; i < n; ++i) {
			ms[i] = nextInt();
		}
		for (int i = 0; i < n; ++i) {
			vs[i] = nextInt();
		}
		Lemming[] lemmings = new Lemming[n];
		for (int i = 0; i < n; ++i) {
			lemmings[i] = new Lemming(ms[i], vs[i], i + 1);
		}
		Arrays.sort(lemmings);
		double l = 0., r = 1e9;
		for (int it = 0; it < 100; ++it) {
			double t = (l + r) / 2;
			int j = 0;
			for (int i = 0; i < n && j < k; ++i) {
				if ((j + 1) * h <= t * lemmings[i].v) {
					j++;
				}
			}
			if (j == k) {
				r = t;
			} else {
				l = t;
			}
		}
		int j = 0;
		for (int i = 0; i < n && j < k; ++i) {
			if ((j + 1) * h <= r * lemmings[i].v) {
				out.print(lemmings[i].id + " ");
				j++;
			}
		}
		out.println();
		
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