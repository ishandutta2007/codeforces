import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	long f(long a, long b, long c) {
		return (a + 1) * (b + 2) * (c + 2) - a * b * c;
	}
	
	void solve() throws Exception {
		int n = nextInt();
		long max = Long.MIN_VALUE;
		long min = Long.MAX_VALUE;
		ArrayList<Integer> divs = new ArrayList<Integer>();
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				divs.add(i);
				if (i * i != n) {
					divs.add(n / i);
				}
			}
		}
		Collections.sort(divs);
		int cnt = divs.size();
		for (int i = 0; i < cnt; i++) {
			for (int j = i; j < cnt; j++) {
				long tmp = (long) divs.get(i) * (long) divs.get(j);
				if (tmp > n) {
					break;
				}
				if (n % tmp != 0) {
					continue;
				}
				long a = n / tmp;
				long res = f(a, divs.get(i), divs.get(j));
				min = Math.min(res, min);
				max = Math.max(res, max);
			}
		}
		
		
		out.println(min + " " + max);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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