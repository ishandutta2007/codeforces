import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();

		int[] p = new int[n];
		int[] s = new int[n];
		int[] chosen = new int[m];

		for (int i = 0; i < n; ++i) {
			p[i] = in.nextInt();
		}
		for (int i = 0; i < n; ++i) {
			s[i] = in.nextInt() - 1;
			chosen[s[i]] = max(chosen[s[i]], p[i]);
		}

		int ans = 0;
		while (k-- > 0) {
			int c = in.nextInt() - 1;
			if (p[c] != chosen[s[c]]) {
				++ans;
			}
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