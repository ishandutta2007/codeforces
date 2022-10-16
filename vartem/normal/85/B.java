import java.io.*;
import java.util.*;

public class Queue {

	void solve() throws Exception {
		int k1 = nextInt();
		int k2 = nextInt();
		int k3 = nextInt();
		int t1 = nextInt();
		int t2 = nextInt();
		int t3 = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		ArrayDeque<Long> a1 = new ArrayDeque<Long>();
		ArrayDeque<Long> a2 = new ArrayDeque<Long>();
		ArrayDeque<Long> a3 = new ArrayDeque<Long>();
		
		long ans = -1;
		for (int i = 0; i < n; i++) {
			long t = a[i];
			
			if (a1.size() == k1) {
				t = Math.max(t, a1.poll());
			}
			t += t1;
			a1.add(t);
			
			if (a2.size() == k2) {
				t = Math.max(t, a2.poll());
			}
			t += t2;
			a2.add(t);
			
			if (a3.size() == k3) {
				t = Math.max(t, a3.poll());
			}
			t += t3;
			a3.add(t);
			
			ans = Math.max(ans, t - a[i]);
		}
		out.println(ans);
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
	final String filename = new String("Queue").toLowerCase();

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
		new Queue().run();
	}

}