
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	long[] d;
	int[] maskLess;
	
	long count(int[] prefix) {
		int n = prefix.length;
		Arrays.fill(d, 0);
		d[0] = 1;
		for (int mask = 0; mask < 1 << n; ++mask) {
			if (d[mask] == 0) {
				continue;
			}
			int i = Integer.bitCount(mask);
			for (int j = 0; j < n; ++j) {
				if ((prefix[j] == -1 || prefix[j] == i) &&
						(mask & 1 << j) == 0 && 
						(mask & maskLess[j]) == maskLess[j]) {
					d[mask | (1 << j)] += d[mask];
				}
			}
		}
		return d[(1 << n) - 1];
	}

	public void solve() throws IOException {
		int n = nextInt();
		long x = nextLong() - 2001;
		int m = nextInt();
		d = new long[1 << n];
		maskLess = new int[n];
		for (int i = 0; i < m; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			maskLess[v] |= 1 << u;
		}
		int[] prefix = new int[n];
		Arrays.fill(prefix, -1);
		for (int i = 0; i < n; ++i) {
			while (true) {
				prefix[i]++;
				if (prefix[i] == n) {
					out.println("The times have changed");
					return;
				}
				long count = count(prefix);
				if (x < count) {
					break;
				} else {
					x -= count;
				}
			}
		}
		for (int i : prefix) {
			out.print((i + 1) + " ");
		}
		out.println();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
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
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}