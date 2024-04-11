import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int a = sc.nextInt();
		if (a == 3) {
			System.out.println(1);
		} else if (a == 1) {
			System.out.println(2);
		} else if (a == 4) {
			System.out.println(2);
		} else if (a == 2) {
			System.out.println(3);
		} else if (a == 5) {
			System.out.println(1);
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}