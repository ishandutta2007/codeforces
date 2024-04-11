
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
		int[] next = new int[n];
		int[] cap = new int[n];
		boolean[] in = new boolean[n];
		Arrays.fill(next, -1);
		for (int i = 0; i < m; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			int c = nextInt();
			in[v] = true;
			next[u] = v;
			cap[u] = c;
		}
		ArrayList<String> ans = new ArrayList<String>();
		for (int i = 0; i < n; ++i) {
			if (!in[i] && next[i] != -1) {
				int j = next[i];
				int c = cap[i];
				while (next[j] != -1) {
					c = Math.min(c, cap[j]);
					j = next[j];
				}
				ans.add((i + 1) + " " + (j + 1) + " " + c);
			}
		}
		out.println(ans.size());
		for (String s : ans) {
			out.println(s);
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