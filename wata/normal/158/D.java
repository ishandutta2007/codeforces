import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) t[i] = sc.nextInt();
		int res = Integer.MIN_VALUE;
		for (int i = 1; i * 3 <= n; i++) if (n % i == 0) {
			int[] tmp = new int[i];
			for (int j = 0; j < n; j++) tmp[j % i] += t[j];
			for (int j = 0; j < i; j++) res = max(res, tmp[j]);
		}
		System.out.println(res);
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}