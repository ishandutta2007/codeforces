import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		long x = nextLong();
		long y = nextLong();
		long[] a = new long[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextLong();
		}
		long[] b = new long[m];
		for (int i = 0; i < m; ++i) {
			b[i] = nextLong();
		}
		ArrayList<Integer> ansu = new ArrayList<Integer>();
		ArrayList<Integer> ansv = new ArrayList<Integer>();
		for (int i = 0, j = 0; i < n && j < m; ++i) {
			while (j < m && b[j] < a[i] - x) {
				++j;
			}
			if (j < m && b[j] <= a[i] + y) {
				ansu.add(i + 1);
				ansv.add(j + 1);
				++j;
			}
		}
		out.println(ansu.size());
		for (int i = 0; i < ansu.size(); ++i) {
			out.println(ansu.get(i) + " " + ansv.get(i));
		}
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