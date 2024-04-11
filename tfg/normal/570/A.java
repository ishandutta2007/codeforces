import java.io.*;
import java.util.*;

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
		int m = in.nextInt();
		int n = in.nextInt();
		int[] votes = new int[m];
		Arrays.fill(votes, 0);
		for(int i = 0; i < n; i++) {
			int wins = -1;
			int idx = -1;
			for(int j = 0; j < m; j++) {
				int got = in.nextInt();
				if(got > wins) {
					wins = got;
					idx = j;
				}
			}
			votes[idx]++;
		}
		int ans = 0;
		for(int i = 0; i < m; i++) {
			if(votes[i] > votes[ans]) {
				ans = i;
			}
		}
		out.println(ans + 1);
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