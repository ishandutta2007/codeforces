import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	int get(char a, char b) {
		if (a == b) {
			return 0;
		}
		if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P')
				|| (a == 'P' && b == 'R')) {
			return 1;
		} else {
			return 2;
		}
	}

	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}

	void solve() throws Exception {
		int n = nextInt();
		String s1 = nextToken();
		String s2 = nextToken();
		int lcm = s1.length() * s2.length() / gcd(s1.length(), s2.length());
		int[] win = new int[lcm];
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < lcm; i++) {
			int x = i % s1.length();
			int y = i % s2.length();
			win[i] = get(s1.charAt(x), s2.charAt(y));
			if (win[i] == 1) {
				sum1++;
			}
			if (win[i] == 2) {
				sum2++;
			}
		}
		
		int count = n / lcm;
		sum1 *= count;
		sum2 *= count;
		for (int i = 0; i < n % lcm; i++) {
			if (win[i] == 1) {
				sum1++;
			}
			if (win[i] == 2) {
				sum2++;
			}
		}
		out.println(sum2 + " " + sum1);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

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