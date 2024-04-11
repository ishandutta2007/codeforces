import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
		}

		int[] cnt = new int[200000];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				++cnt[a[i] + a[j]];
			}
		}

		int ans = 0;
		for (int i = 0; i < cnt.length; ++i) {
			ans = max(ans, cnt[i]);
		}
		out.println(ans);

		out.close();
	}
}

class InputReader {
	public BufferedReader read;
	public StringTokenizer token;

	public InputReader(InputStream str) {
		read = new BufferedReader(new InputStreamReader(str), 1 << 15);
	}

	public String next() {
		while (token == null || !token.hasMoreTokens()) {
			try {
				token = new StringTokenizer(read.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return token.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}