
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		int n = nextInt();
		double w = nextDouble();
		int m = nextInt();
		int count = 0, cur = m, c = 0;
		for (int i = 0, j = 0; i < n || j < m; ) {
			int value = Math.min(n - count, cur);
			count += value;
			cur -= value;
			if (cur == 0) {
				if (c >= 2) {
					out.println("NO");
					return;
				}
				c = 0;
				cur = m;
				++i;
			}
			if (count == n) {
				count = 0;
				j++;
				if (cur != m) {
					c++;
				}
			}
		}
		out.println("YES");
		count = 0; cur = m;
		for (int i = 0, j = 0; i < n || j < m; ) {
			int value = Math.min(n - count, cur);
			out.print((i + 1) + " " + value * w / m + " ");
			count += value;
			cur -= value;
			if (count == n) {
				count = 0;
				j++;
				out.println();
			}
			if (cur == 0) {
				cur = m;
				++i;
			}
		}
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