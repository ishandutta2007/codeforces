import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] word = new String[n];
		for (int i = 0; i < n; i++) {
			word[i] = sc.next();
		}
		int k = word[0].length();
		long[] bad = new long[1 << k];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int diff = 0;
				for (int p = 0; p < k; p++) {
					if (word[i].charAt(p) == word[j].charAt(p)) {
						diff |= 1 << p;
					}
				}
				bad[diff] |= (1L << i) + (1L << j);
			}
		}
		double[] f = new double[1 << k];
		for (int t = (1 << k) - 1; t >= 0; t--) {
			for (int i = 0; i < k; i++) {
				if ((t & (1 << i)) > 0) {
					bad[t ^ (1 << i)] |= bad[t];
				}
			}
			int cnt = 0;
			for (int i = 0; i < k; i++) {
				if ((t & (1 << i)) == 0) {
					f[t] += f[t ^ (1 << i)];
					cnt++;
				}
			}
			if (cnt > 0) {
				f[t] /= cnt;
			}
			f[t] += Long.bitCount(bad[t]) * 1.0 / n;
		}
		System.out.println(f[0]);
	}
}