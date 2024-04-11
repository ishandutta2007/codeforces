import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	long mod = 51123987;

	void solve() throws IOException {
		int n = nextInt();
		String s = next();
//		Random rnd = new Random(42);
//		StringBuilder sb = new StringBuilder();
//		for (int i = 0; i < n; ++i) {
//			sb.append((char)(rnd.nextInt(1) + 'a'));
//		}
//		String s = sb.toString();
		int[] p1 = palin1(s);
		int[] p2 = palin2(s);
		long[] startsInc = new long[n + 2];
		long[] endsInc = new long[n + 2];
		for (int i = 0; i < n - 1; ++i) {
			startsInc[i - p1[i] + 1]++;
			startsInc[i + 1]--;
			endsInc[i + 2]++;
			endsInc[i + p1[i] + 2]--;
		}
		for (int i = 0; i < n; ++i) {
			startsInc[i - p2[i]]++;
			startsInc[i + 1]--;
			endsInc[i + 1]++;
			endsInc[i + p2[i] + 2]--;
		}
		long ans = 0;
		long starts = 0, ends = 0;
		long sum = 0;
		long inv2 = BigInteger.valueOf(2).modInverse(BigInteger.valueOf(mod)).longValue();
		for (int i = 0; i <= n; ++i) {
			starts = mod(starts + startsInc[i]);
			ends = mod(ends + endsInc[i]);
			sum = mod(sum - ends);
			ans = mod(ans + mod(sum * starts) + mod(mod(starts * (starts - 1)) * inv2));
			sum = mod(sum + starts);
		}
		out.println(ans);
	}

	private long mod(long l) {
		l %= mod;
		while (l < 0) {
			l += mod;
		}
		return l;
	}

	private int[] palin1(String s) {
		int n = s.length();
		int[] a = new int[n - 1];
		int l = -1, r = -1;
		//i-a[i]+1 .. i+a[i]
		for (int i = 0; i < n - 1; ++i) {
			if (i < r) {
				a[i] = Math.min(r - i, a[l + r - i - 1]);
			}
			while (i - a[i] >= 0 && i + a[i] + 1 < n && s.charAt(i - a[i]) == s.charAt(i + a[i] + 1)) {
				a[i]++;
			}
			if (i + a[i] > r) {
				l = i - a[i] + 1;
				r = i + a[i];
			}
		}
		return a;
	}

	private int[] palin2(String s) {
		int n = s.length();
		int[] a = new int[n];
		int l = -1, r = -1;
		//i-a[i] .. i+a[i]
		for (int i = 0; i < n; ++i) {
			if (i < r) {
				a[i] = Math.min(r - i, a[l + r - i]);
			}
			while (i - a[i] - 1 >= 0 && i + a[i] + 1 < n && s.charAt(i - a[i] - 1) == s.charAt(i + a[i] + 1)) {
				a[i]++;
			}
			if (i + a[i] > r) {
				l = i - a[i];
				r = i + a[i];
			}
		}
		return a;
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}