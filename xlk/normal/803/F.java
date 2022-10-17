import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = 100000;
		int p = 1000000007;
		int c[] = new int[m + 1];
		int s[] = new int[m + 1];
		int b[] = new int[m + 1];
		for (int i = 0; i < n; i++) {
			c[in.nextInt()]++;
		}
		b[0] = 1;
		for (int i = 1; i <= m; i++) {
			b[i] = b[i - 1] * 2 % p;
			for (int j = i; j <= m; j += i) {
				s[i] += c[j];
			}
		}
		int v[] = new int[m + 1];
		int u[] = new int[m + 1];
		for (int i = 2; i <= m; i++) {
			if (v[i] > 0) {
				continue;
			}
			for (int j = i; j <= m; j += i) {
				v[j] = i;
			}
		}
		u[1] = 1;
		for (int i = 2; i <= m; i++) {
			if (v[i] == v[i / v[i]]) {
				u[i] = 0;
			} else {
				u[i] = -u[i / v[i]];
			}
		}
		int z = 0;
		for (int i = 1; i <= m; i++) {
			z += u[i] * (b[s[i]] - 1);
			if (z >= p) {
				z -= p;
			}
			if (z < 0) {
				z += p;
			}
		}
		System.out.println(z);
	}
}