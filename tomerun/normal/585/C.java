import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		long X = sc.nextLong();
		long Y = sc.nextLong();
		System.out.println(solve(X, Y));
	}

	static String solve(long x, long y) {
		StringBuilder sb = new StringBuilder();
		while (x != y && x > 0 && y > 0) {
			if (x > y) {
				if (y == 1) {
					sb.append((x - 1) + "A");
					x = 1;
					break;
				}
				sb.append((x / y) + "A");
				x %= y;
			} else {
				if (x == 1) {
					sb.append((y - 1) + "B");
					y = 1;
					break;
				}
				sb.append((y / x) + "B");
				y %= x;
			}
		}
		if (x == 1 && y == 1) {
			return sb.toString();
		} else {
			return "Impossible";
		}
	}
}