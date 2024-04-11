import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		long a = sc.nextLong();
		long res = 1;
		for (long i = 2; i <= a; i++) {
			res += (i * 2 - 2) * 6;
		}
		System.out.println(res);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}