import java.util.Scanner;

public class A {
	static Scanner sc = new Scanner(System.in);
	static int n;

	public static void main(String[] args) throws Exception {
		n = sc.nextInt();
		int m = sc.nextInt();
		boolean[][] flag = new boolean[n][10];
		for (int i = 0; i < n; ++i) {
			String line = sc.next();
			for (char c : line.toCharArray()) {
				flag[i][c - '0'] = true;
			}
		}
		System.out.println(valid(flag) ? "YES" : "NO");
	}

	static boolean valid(boolean[][] flag) {
		for (int i = 0; i < n; ++i) {
			boolean found = false;
			for (int j = 0; j < 10; ++j) {
				if (flag[i][j]) {
					if (found) {
						return false;
					}
					found = true;
					if (i > 0 && flag[i - 1][j]) return false;
				}
			}
		}
		return true;
	}

}