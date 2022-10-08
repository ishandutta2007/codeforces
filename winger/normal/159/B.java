import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] sum1 = new int[1000];
		int[][] c1 = new int[1000][1000];
		for (int i = 0; i < n; ++i) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			sum1[u]++;
			c1[u][v]++;
		}
		int[] sum2 = new int[1000];
		int[][] c2 = new int[1000][1000];
		for (int i = 0; i < m; ++i) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			sum2[u]++;
			c2[u][v]++;
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < 1000; ++i) {
			ans1 += Math.min(sum1[i], sum2[i]);
			for (int j = 0; j < 1000; ++j) {
				ans2 += Math.min(c1[i][j], c2[i][j]);
			}
		}
		out.println(ans1 + " " + ans2);
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