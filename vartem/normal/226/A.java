import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Aliens {

	final String filename = new String("Aliens").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		
		BigInteger ans = BigInteger.valueOf(3).modPow(BigInteger.valueOf(n), BigInteger.valueOf(m));
		int result = ans.intValue();
		result += m - 1;
		result %= m;
		out.println(result);
		
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
		new Aliens().run();
	}

}