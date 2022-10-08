import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int[] cs = new int[5];
		for (int i = 0; i < n; ++i) {
			cs[nextInt()]++;
		}
		int ans = cs[4];
		ans += cs[3];
		cs[1] = Math.max(0, cs[1] - cs[3]);
		ans += (cs[2] + 1) / 2;
		cs[2] %= 2;
		cs[1] = Math.max(0, cs[1] - 2 * cs[2]);
		ans += (cs[1] + 3) / 4;
		out.println(ans);
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