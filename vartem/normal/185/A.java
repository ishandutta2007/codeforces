import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Temp {

	final String filename = new String("Temp").toLowerCase();

	void solve() throws Exception {
		long n = nextLong();
		long longMod = 1000 * 1000 * 1000 + 7;
		BigInteger mod = BigInteger.valueOf(longMod);
		long count = BigInteger.valueOf(2).modPow(BigInteger.valueOf(n), mod).longValue();
		count = (count * (count + 1)) / 2;
		out.println(count % longMod);
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
		new Temp().run();
	}

}