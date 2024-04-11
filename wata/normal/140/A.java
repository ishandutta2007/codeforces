import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), R = sc.nextInt(), r = sc.nextInt();
		if (R < r) {
			System.out.println("NO");
		} else if (n == 1) {
			System.out.println("YES");
		} else if (R < 2 * r) {
			System.out.println("NO");
		} else {
			double th = 2 * asin((double)r / (R - r));
			if (th * n <= 2 * PI + 1e-10) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}