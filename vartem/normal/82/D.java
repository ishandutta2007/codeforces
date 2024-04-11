import java.io.*;
import java.util.*;

public class TwoOutOfThree {
	long[][] r;
	int[] a;
	final long inf = Long.MAX_VALUE / 2;
	int n;
	
	long go(int i, int t) {
		if (i >= n) {
			if (t == n) 
				return 0;
			else
				return a[t];
		}
		
		if (r[i][t] != -1) {
			return r[i][t];
		}
		r[i][t] = inf;
		
		if (t == n) {		
			
			if (i == n - 1) {
				r[i][t] = a[i];
				return r[i][t];
			} 
			
			if (i == n - 2) {
				r[i][t] = Math.max(a[i], a[i + 1]);
				return r[i][t];
			}
			
			long res = inf;
			res = Math.min(res, go(i + 3, i) + Math.max(a[i + 2], a[i + 1]));
			res = Math.min(res, go(i + 2, n) + Math.max(a[i], a[i + 1]));
			res = Math.min(res, go(i + 3, i + 1) + Math.max(a[i], a[i + 2]));
			r[i][t] = res;
			return res;
			
		} else {
			if (i == n - 1) {
				r[i][t] = Math.max(a[i], a[t]);
				return r[i][t];
			}
			
			if (i == n) {
				r[i][t] = a[t];
				return r[i][t];
			}
						
			long res = inf;
			
			res = Math.min(res, go(i + 1, n) + Math.max(a[i], a[t]));
			res = Math.min(res, go(i + 2, t) + Math.max(a[i], a[i + 1]));
			res = Math.min(res, go(i + 2, i) + Math.max(a[t], a[i + 1]));
			
			r[i][t] = res;
			return res;
		}
	}
	
	void print(int i, int t) {
		if (i >= n) {
			out.println(t + 1);
			return;
		}
		
		if (t == n) {			
			
			if (i == n - 1) {
				out.println(i + 1);
				return;
			} 
			
			if (i == n - 2) {
				out.println((i + 2) + " " + (i + 1));
				return;
			}
			
			if (r[i][t] == go(i + 3, i) + Math.max(a[i + 2], a[i + 1])) {
				out.println((i + 3) + " " + (i + 2));
				print(i + 3, i);
				return;
			}
			if (r[i][t] == go(i + 2, n) + Math.max(a[i], a[i + 1])) {
				out.println((i + 1) + " " + (i + 2));
				print(i + 2, n);
				return;
			}
			if (r[i][t] == go(i + 3, i + 1) + Math.max(a[i + 2], a[i])) {
				out.println((i + 1) + " " + (i + 3));
				print(i + 3, i + 1);
				return;
			}
			return;
			
		} else {
			if (i == n - 1) {
				out.println((i + 1) + " " + (t + 1));
				return;
			}
			
			if (i == n) {
				out.println(t + 1);
				return;
			}
						
			long res = inf;
			
			if (r[i][t] == go(i + 1, n) + Math.max(a[i], a[t])) {
				out.println((i + 1) + " " + (t + 1));
				print(i + 1, n);
				return;
			} 
			if (r[i][t] == go(i + 2, t) + Math.max(a[i], a[i + 1])) {
				out.println((i + 1) + " " + (i + 2));
				print(i + 2, t);
				return;
			} 
			if (r[i][t] == go(i + 2, i) + Math.max(a[i + 1], a[t])) {
				out.println((i + 2) + " " + (t + 1));
				print(i + 2, i);
				return;
			} 
		}
	}
	
	void solve() throws Exception {
		n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		r = new long[n][n + 1];
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n + 1; j++)
				r[i][j] = -1;
		long ans = go(0, n);
		out.println(ans);
		print(0, n);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

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
	final String filename = new String("TwoOutOfThree").toLowerCase();

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
		new TwoOutOfThree().run();
	}

}