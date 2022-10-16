import java.io.*;
import java.util.*;

public class A {

	int n, m;
	int[] a, b, d;
	boolean[] used;	
	
	void solve() throws Exception {
		n = nextInt();
		int p = nextInt();
		int[] next = new int[n];
		int[] d = new int[n];
		boolean[] hasInc = new boolean[n];
		Arrays.fill(next, -1);
		for (int i = 0; i < p; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			int diam = nextInt();
			next[a] = b;
			d[a] = diam;
			hasInc[b] = true;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (!hasInc[i] && next[i] != -1)
				ans++;
		out.println(ans);
		for (int i = 0; i < n; i++) 
			if (!hasInc[i] && next[i] != -1) {
				int j = i;
				int min = Integer.MAX_VALUE;
				while (next[j] != -1) {
					min = Math.min(d[j], min);
					j = next[j];
				}
				out.println((i + 1) + " " + (j + 1) + " " + min);
			}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader(filename + ".in"));
			//			out = new PrintWriter(filename + ".out");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("A").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new A().run();
	}

}