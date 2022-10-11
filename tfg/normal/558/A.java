import java.util.Scanner;
import java.util.Arrays;

final public class Main {
	static private Scanner sc;
	static public void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();
		int off = 100000;
		int[] a = new int[n];
		int[] f = new int[2 * off + 10];
		Arrays.fill(f, 0);
		int great = 0;
		for(int i = 0; i < n; i++) {
			int on = sc.nextInt() + off;
			if(on > off)
				great++;
			f[on] += sc.nextInt();
		}
		int right, left;
		if(great > n - great) {
			right = n - great + 1;
			left = n - great;
		}
		else if(great == n - great) {
			right = great;
			left = great;
		}
		else {
			right = great;
			left = great + 1;
		}
		int ans = 0;
		for(int i = off; left > 0; i--) {
			if(f[i] > 0) {
				ans += f[i];
				left--;
			}
		}
		for(int i = off; right > 0; i++) {
			if(f[i] > 0) {
				ans += f[i];
				right--;
			}
		}
		System.out.println(ans);
	}
}