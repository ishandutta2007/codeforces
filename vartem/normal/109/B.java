import java.io.*;
import java.util.*;

public class B {

	ArrayList<Long> a;
	long n;
	void go(long k) {
		if (k > n)
			return;
		if (k > 0L) {
			a.add(k);
		}
		go(10L * k + 4L);
		go(10L * k + 7L);
	}
	
	void solve() throws Exception {
		long pl = nextInt();
		long pr = nextInt();
		long vl = nextInt();
		long vr = nextInt();
		int k = nextInt();
		n = Math.max(pr, vr);
		a = new ArrayList<Long>();
		go(0);
		a.add(0L);
		a.add((long) Integer.MAX_VALUE / 2);
		Collections.sort(a);
		System.err.println(a.toString());
		long ans = 0;
		int i = 1;
		int j = k;
		
		while (j < a.size() - 1) {
			long l1 = a.get(i - 1) + 1;
			long r1 = a.get(i);
			
			long l2 = a.get(j);
			long r2 = a.get(j + 1) - 1;
			
			l1 = Math.max(l1, pl);
			r1 = Math.min(r1, pr);
			
			l2 = Math.max(l2, vl);
			r2 = Math.min(r2, vr);
			j++; i++;
			if (l1 > r1 || l2 > r2)
				continue;
			ans += (r1 - l1 + 1) * (r2 - l2 + 1);
			
		}
		i = 1;
		j = k;
		while (j < a.size() - 1) {
			long l1 = a.get(i - 1) + 1;
			long r1 = a.get(i);
			
			long l2 = a.get(j);
			long r2 = a.get(j + 1) - 1;
			
			l1 = Math.max(l1, vl);
			r1 = Math.min(r1, vr);
			
			l2 = Math.max(l2, pl);
			r2 = Math.min(r2, pr);
			j++; i++;
			if (l1 > r1 || l2 > r2)
				continue;
			ans += (r1 - l1 + 1) * (r2 - l2 + 1);
			
		}
		if (k == 1) {
			long l = Math.max(pl, vl);
			long r = Math.min(pr, vr);
			for (long t : a) {
				if (t >= l && t <= r) {
					ans--;
				}
			}
		}
		long m = (pr - pl + 1) * (vr - vl + 1);
		double res = ((double) ans) / ((double) m);
		out.printf("%.14f", res);
	}

	void run() {
		try {
			Locale.setDefault(Locale.US);
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