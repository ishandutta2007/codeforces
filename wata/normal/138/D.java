import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;

import java.math.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	int n, m;
	char[][] map;
	int[][][][][] grundy;
	
	int grundy(int odd, int s1, int t1, int s2, int t2) {
		if (s1 >= t1 || s2 >= t2) return 0;
		if (grundy[odd][s1 + m][t1 + m][s2][t2] != -1) return grundy[odd][s1 + m][t1 + m][s2][t2];
		BitSet bset = new BitSet();
		for (int i = 0; i < n; i++) {
			for (int j = (i + odd) % 2; j < m; j += 2) if (s1 <= i - j && i - j <= t1 && s2 <= i + j && i + j <= t2) {
				if (map[i][j] == 'L') {
					bset.set(grundy(odd, s1, t1, s2, i + j - 1) ^ grundy(odd, s1, t1, i + j + 1, t2));
				} else if (map[i][j] == 'R') {
					bset.set(grundy(odd, s1, i - j - 1, s2, t2) ^ grundy(odd, i - j + 1, t1, s2, t2));
				} else {
					bset.set(grundy(odd, s1, i - j - 1, s2, i + j - 1) ^ grundy(odd, i - j + 1, t1, s2, i + j - 1) ^ grundy(odd, s1, i - j - 1, i + j + 1, t2) ^ grundy(odd, i - j + 1, t1, i + j + 1, t2));
				}
			}
		}
		int g = bset.nextClearBit(0);
		grundy[odd][s1 + m][t1 + m][s2][t2] = g;
		return g;
	}
	
	void run() {
		n = sc.nextInt();
		m = sc.nextInt();
		map = new char[n][];
		for (int i = 0; i < n; i++) map[i] = sc.next().toCharArray();
		grundy = new int[2][n + m + 1][n + m + 1][n + m + 1][n + m + 1];
		for (int i = 0; i < grundy.length; i++) for (int j = 0; j < grundy[i].length; j++) for (int k = 0; k < grundy[i][j].length; k++) for (int h = 0; h < grundy[i][j][k].length; h++) fill(grundy[i][j][k][h], -1);
		System.out.println((grundy(0, -m, n, 0, n + m) ^ grundy(1, -m, n, 0, n + m)) == 0 ? "LOSE" : "WIN");
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}