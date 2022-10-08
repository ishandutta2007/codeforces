import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class F {
	Scanner sc = new Scanner(System.in);
	
	char[] S = "klmnopgrstuvwnypabcdefghiz".toCharArray();
	
	void run() {
//		while (sc.hasNextLine()) {
//			char[] cs = sc.nextLine().toCharArray();
//			for (char c : cs) {
//				if ('a' <= c && c <= 'z') System.out.print(S[c - 'a']);
//				else System.out.print(c);
//			}
//			System.out.println();
//		}
		boolean[] isPrime = eratos(2000000);
		int n = sc.nextInt();
		for (int i = 0; ; i++) if (isPrime[i]) {
			int r = rev(i);
			if (isPrime[r] && i != r) {
				n--;
				if (n == 0) {
					System.out.println(i);
					return;
				}
			}
		}
	}
	
	int rev(int i) {
		int r = 0;
		while (i > 0) {
			r = r * 10 + i % 10;
			i /= 10;
		}
		return r;
	}
	
	boolean[] eratos(int n) {
		boolean[] isPrime = new boolean[n];
		for (int i = 3; i < n; i += 2) isPrime[i] = true;
		if (n < 3) return isPrime;
		isPrime[2] = true;
		for (int i = 3; i * i < n; i += 2) if (isPrime[i]) {
			for (int j = i * i, k = i * 2; j < n; j += k) {
				isPrime[j] = false;
			}
		}
		return isPrime;
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new F().run();
	}
}