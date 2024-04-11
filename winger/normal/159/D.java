import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	long solve(long maxu, long maxv, long maxsum) {
		maxu = Math.min(maxu, maxsum);
		maxv = Math.min(maxv, maxsum);
		long k = (maxu + maxv - 2) - (maxsum - 1);
		if (k < 0) {
			k = 0;
		}
		return maxu * maxv - k * (k + 1) / 2;
	}
	
	public void solve() throws IOException {
		String s = next();
		int n = s.length();
		int[] c1 = new int[n]; // i-u .. i+u
		for (int i = 0; i < n; ++i) {
			while (i - c1[i] >= 0 && i + c1[i] < n && s.charAt(i - c1[i]) == s.charAt(i + c1[i])) {
				++c1[i];
			}
		}
		int[] c2 = new int[n - 1]; // i-v .. i+v+1
		for (int i = 0; i < n - 1; ++i) {
			while (i - c2[i] >= 0 && i + c2[i] + 1 < n && s.charAt(i - c2[i]) == s.charAt(i + c2[i] + 1)) {
				++c2[i];
			}
		}
		//System.out.println(Arrays.toString(c1) + " " + Arrays.toString(c2));
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				//u+v<j-i
				ans += solve(c1[i], c1[j], j - i);
				if (j < n - 1) {
					ans += solve(c1[i], c2[j], j - i);
				}
			}
		}
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 2; j < n; ++j) {
				//u+v<j-i-1
				ans += solve(c2[i], c1[j], j - i - 1);
				if (j < n - 1) {
					ans += solve(c2[i], c2[j], j - i - 1);
				}
			}
		}
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