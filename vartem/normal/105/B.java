import java.io.*;
import java.util.*;

public class B {

	int n, k;
	double A;
	int[] b, l;
	double ans;
	double curAns;
	
	void check(boolean[] used) {
		int cnt = 0;
		for (boolean t : used)
			if (t)
				cnt++;
		double prob = 1;
		for (int i = 0; i < n; i++) {
			if (used[i])
				prob *= ((double) l[i]) / ((double) 100);
			else
				prob *= 1 - ((double) l[i]) / ((double) 100);
		}
		if (2 * cnt > n) {
			curAns += prob;
		} else {
			int level = 0;
			for (int i = 0; i < n; i++)
				if (!used[i])
					level += b[i];
			curAns += prob * ( A / ((double) A + level));
		}
	}
	
	void go(int i, boolean[] used) {
		if (n == i) {
			check(used);
			return;
		}
		used[i] = true;
		go(i + 1, used);
		used[i] = false;
		go(i + 1, used);
	}
	
	void candies(int k, int i) {
		if (i == n) {
			curAns = 0;
			go(0, new boolean[n]);
			if (curAns > ans)
				ans = curAns;
			return;
		}
		candies(k, i + 1);
		for (int j = 1; j <= k && l[i] + 10 * j <= 100; j++) {
			l[i] += 10 * j;
			candies(k - j, i + 1);
			l[i] -= 10 * j;
		}
	}
	
	void solve() throws Exception {
		n = nextInt();
		k = nextInt();
		A = nextInt();
		b = new int[n];
		l = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = nextInt();
			l[i] = nextInt();		
		}
		ans = 0;
		candies(k, 0);
		out.printf("%.12f", ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader(filename + ".in"));
			//			out = new PrintWriter(filename + ".out");
			Locale.setDefault(Locale.US);
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
	final String filename = new String("B").toLowerCase();

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
		new B().run();
	}

}