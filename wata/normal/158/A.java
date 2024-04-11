import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = sc.nextInt();
		if (a[0] == 0) {
			System.out.println(0);
			return;
		}
		while (a[k - 1] == 0) k--;
		int r = a[k - 1];
		while (k < n && a[k] == r) k++;
		System.out.println(k);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new A().run();
	}
}