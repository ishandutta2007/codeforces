import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private int[] phi;
	private int[] count;

	void solve() throws IOException {
		int n = nextInt();
		phi = new int[n];
		count = new int[2002];
		rec(0, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int len = i == j ? 0 : phi[i] + phi[j] + 1;
				out.print(len + " ");
			}
			out.println();
		}
//		Random rnd = new Random(42);
//		loop: while (true) {
//			int[] phi = new int[n];
//			for (int i = 0; i < n; ++i) {
//				phi[i] = rnd.nextInt(500);
//			}
//			boolean[] col = new boolean[1001];
//			for (int i = 0; i < n; ++i) {
//				for (int j = i + 1; j < n; ++j) {
//					if (i == j) {
//						continue;
//					}
//					int len = phi[i] + phi[j] + 1;
//					if (len > 1000 || col[len]) {
//						continue loop;
//					}
//					col[len] = true;
//				}
//			}
//			System.err.println(Arrays.toString(phi));
//			int[][] dist = new int[n][n];
//			for (int i = 0; i < n; ++i) {
//				for (int j = 0; j < n; ++j) {
//					int len = i == j ? 0 : phi[i] + phi[j] + 1;
//					dist[i][j] = len;
//					out.print(len + " ");
//				}
//				out.println();
//			}
//			return;
//		}
	}

	private boolean rec(int i, int min) {
		if (i == phi.length) {
			return true;
		}
		for (phi[i] = min; phi[i] <= 1000; ++phi[i]) {
			boolean ok = true;
			for (int j = 0; j < i; ++j) {
				ok &= count[phi[i] + phi[j] + 1] == 0;
				count[phi[i] + phi[j] + 1]++;
			}
			if (ok && rec(i + 1, phi[i] + 1)) {
				return true;
			}
			for (int j = 0; j < i; ++j) {
				count[phi[i] + phi[j] + 1]--;
			}
		}
		return false;
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}