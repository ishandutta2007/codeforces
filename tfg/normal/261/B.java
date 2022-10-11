import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class a {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		solve(in, out);
		out.close();
	}

	static private void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		int sum = 0;
		for(int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			sum += a[i];
		}
		int cap = in.nextInt();
		if(sum <= cap) {
			out.println(n);
			return;
		}
		Arrays.sort(a);
		BigInteger[] count = new BigInteger[n];
		for(int i = 0; i < n; i++) {
			count[i] = new BigInteger("0");
		}
		for(int i = 0; i < n; i++) {
			BigInteger[][] dp = new BigInteger[n][cap + 1];
			for(int j = 0; j < n; j++) {
				for(int k = 0; k <= cap; k++) {
					dp[j][k] = new BigInteger("0");
				}
			}
			dp[0][0] = new BigInteger("1");
			for(int j = 0; j < n; j++) {
				if(j == i) {
					continue;
				}
				for(int people = n - 1; people > 0; people--) {
					for(int got = cap; got >= a[j]; got--) {
						dp[people][got] = dp[people][got].add(dp[people - 1][got - a[j]]);
					}
				}
			}
			for(int people = n - 1; people > 0; people--) {
				for(int got = cap; got + a[i] > cap && got >= 0; got--) {
					count[people] = count[people].add(dp[people][got]);
				}
			}
		}
		BigInteger[] fat = new BigInteger[n + 1];
		fat[0] = new BigInteger("1");
		for(int i = 1; i <= n; i++) {
			fat[i] = fat[i - 1].multiply(new BigInteger("" + i));
		}
		BigInteger ans = new BigInteger("0");
		for(int i = 1; i < n; i++) {
			ans = ans.add(count[i].multiply(new BigInteger("" + i)).multiply(fat[i]).multiply(fat[n-i-1]));
		}
		out.print(ans.divide(fat[n]) + ".");
		ans = ans.remainder(fat[n]);
		for(int i = 0; i < 20; i++) {
			ans = ans.multiply(new BigInteger("10"));
			out.print(ans.divide(fat[n]));
			ans = ans.remainder(fat[n]);
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}