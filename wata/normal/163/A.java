import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int M = 1000000007;
	
	void run() {
		char[] S = sc.next().toCharArray();
		char[] T = sc.next().toCharArray();
		int n = S.length, m = T.length;
		int[] crt = new int[m + 1];
		crt[0] = 1;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int[] next = new int[m + 1];
			next[0] = 1;
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += crt[j];
				if (sum >= M) sum -= M;
				if (S[i] == T[j]) {
					next[j + 1] = sum;
					res += sum;
					if (res >= M) res -= M;
				}
			}
			crt = next;
		}
		System.out.println(res);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}