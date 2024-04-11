
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int h = nextInt() - 1;
		while (h < 0 || h >= m);
		int[] s = new int[m];
		int sum = 0;
		for (int i = 0; i < m; ++i) {
			s[i] = nextInt();
			while (s[i] < 1 || s[i] > 100);
			sum += s[i];
		}
		if (sum < n) {
			out.println(-1.);
			return;
		}
		double p = 1.;
		for (int i = sum - n + 1; i < sum; ++i) {
//			System.err.println(i - s[h] + 1);
//			System.err.println(i);
			p *= i - s[h] + 1;
			p /= i;
		}
		out.println(1. - p);
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