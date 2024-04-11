import java.util.*;
import java.math.BigInteger;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		String[] s = new String[h];
		for (int i = 0; i < h; i++) {
			s[i] = sc.next();
		}
		BigInteger[][] b = new BigInteger[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				b[i][j] = BigInteger.ZERO;
			}
		}
		int ans = 0;
		for (int i = h - 1; i >= 0; i--) {
			for (int j = w - 1; j >= 0; j--) {
				BigInteger diff = (s[i].charAt(j) == 'W' ? BigInteger.ONE : BigInteger.ONE.negate());
				diff = diff.subtract(b[i][j]);
				if (diff.compareTo(BigInteger.ZERO) != 0) {
					ans++;
					b[i][j] = b[i][j].add(diff);
				}
				if (i > 0) {
					b[i - 1][j] = b[i - 1][j].add(b[i][j]);
				}
				if (j > 0) {
					b[i][j - 1] = b[i][j - 1].add(b[i][j]);
				}
				if (i > 0 && j > 0) {
					b[i - 1][j - 1] = b[i - 1][j - 1].subtract(b[i][j]);
				}
			}
		}
		System.out.println(ans);
	}
}