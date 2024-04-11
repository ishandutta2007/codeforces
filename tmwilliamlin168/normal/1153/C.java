import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] s = sc.next().toCharArray();
		if (s[0] == '?')
			s[0] = '(';
		if (s[n - 1] == '?')
			s[n - 1] = ')';
		if (s[0] != '(' || s[n - 1] != ')') {
			System.out.println(":(");
			return;
		}
		if ((n & 1) == 1) {
			System.out.println(":(");
			return;
		}
		if (n == 2) {
			System.out.println(new String(s));
			return;
		}
		int c1 = 0;
		int c2 = 0;
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == '(')
				++c1;
			if (s[i] == ')')
				++c2;
		}
		if (c1 + 1 > n / 2 || c2 + 1 > n / 2) {
			System.out.println(":(");
			return;
		}
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == '?') {
				if (c1 + 1 < (n >> 1)) {
					++c1;
					s[i] = '(';
				} else {
					++c2;
					s[i] = ')';
				}
			}
		}
		int x = 0;
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == '(')
				x++;
			else {
				x--;
				if (x < 0) {
					System.out.println(":(");
					return;
				}
			}
		}
		System.out.println(new String(s));
		return;
	}
}