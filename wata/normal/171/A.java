import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		long a = sc.nextLong(), b = sc.nextLong();
		long inv = 0;
		while (b > 0) {
			inv = inv * 10 + b % 10;
			b /= 10;
		}
		System.out.println(a + inv);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}