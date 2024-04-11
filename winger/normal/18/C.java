import java.io.*;
import java.util.*;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[] sum = new int[n + 1];
		for (int i = 0; i < n; ++i) {
			sum[i + 1] = sum[i] + a[i];
		}
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			if (2 * sum[i] == sum[n]) {
				ans++;
			}
		}
		out.println(ans);
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void eat(String line) {
		st = new StringTokenizer(line);
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

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

}