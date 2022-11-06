import java.util.Scanner;

public class C {
	static Scanner sc = new Scanner(System.in);

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public static void main(String[] args) throws Exception {
		long a = sc.nextLong();
		long b = sc.nextLong();
		long x = sc.nextLong();
		long y = sc.nextLong();
		long gcd = gcd(x, y);
		x /= gcd;
		y /= gcd;
		if (a < x || b < y) {
			System.out.println("0 0");
			return;
		}
		long a1 = a / x * x;
		long b1 = a / x * y;
		long a2 = b / y * x;
		long b2 = b / y * y;
		if (b1 > b) {
			System.out.println(a2 + " " + b2);
			return;
		} else if (a2 > a) {
			System.out.println(a1 + " " + b1);
			return;
		} else {
			System.out.println(a2 + " " + b2);
			return;

		}
	}

}