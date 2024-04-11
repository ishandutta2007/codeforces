import java.io.*;
import java.util.*;

public class Doctor {

	void solve() throws Exception {
		int n = nextInt();
		long k = nextLong();
		long[] a = new long[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		long[] b = a.clone();
		Arrays.sort(b);
		long l = 0;
		int t = -1;
		for (int i = 0; i < n; i++) {
			if (b[i] > l) {
				if ((b[i] - l) * (n - i) >= k) {
					t = i;
					break;
				} else {
					k -= (b[i] - l) * (n - i);
					l = b[i];
				}
			} 
		}
		if (t == -1) {
			out.println(-1);
			return;
		}
		t = n - t;
		long k1 = k % t;
		long k2 = k / t;
		for (int i = 0; i < a.length; i++) {
			if (a[i] > l)
				a[i] -= l;
			else
				a[i] = -1; 
		}
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			if (a[i] == -1)
				continue;
			if ((k2 >= a[i]) || (k1 > 0 && k2 + 1 == a[i])) {
				a[i] = -1;
				k1--;
				continue;
			}
			
			if (k1 == 0) {
				ans.add(i + 1);
				a[i] = -1;
			}		
			if (k1 > 0)
				k1--;
		}
		
		for (int i = 0; i < a.length; i++) {
			if (a[i] > 0)
				ans.add(i + 1);
		}
		
		for (Integer i : ans) {
			out.print(i + " ");
		}
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
	final String filename = new String("Doctor").toLowerCase();

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
		new Doctor().run();
	}

}