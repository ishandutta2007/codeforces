
import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private int[][] d;


	public void solve() throws IOException {
		long n = nextLong();
		int k = nextInt();
		int[] a = new int[k];
//		a[0] = 2;
//		loop: for (int i = 3, j = 1; j < k; i += 2) {
//			for (int t = 0; a[t] * a[t] <= i; ++t) {
//				if (i % a[t] == 0) {
//					continue loop;
//				}
//			}
//			a[j++] = i;
//		}
		for (int i = 0; i < k; ++i) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int max = (int)Math.min(n + 1, 100000);
		d = new int[k + 1][max];
		Arrays.fill(d[0], 1);
		d[0][0] = 0;
		for (int j = 0; j < k; ++j) {
			for (int i = 1; i < max; ++i) {
				d[j + 1][i] = d[j][i] == 1 && i % a[j] != 0 ? 1 : 0;
			}
		}
		for (int j = 0; j <= k; ++j) {
			for (int i = 1; i < max; ++i) {
				d[j][i] += d[j][i - 1];
			}
		}
		out.println(solve(a, k, n));
	}

	private long solve(int[] a, int k, long n) {
		if (k == 0) {
			return n;
		}
		if (n < d[0].length) {
			return d[k][(int)n];
		}
		return solve(a, k - 1, n) - solve(a, k - 1, n / a[k - 1]);
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