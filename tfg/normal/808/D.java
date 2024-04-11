import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

final public class Main {
	private static boolean solve(long[] a) {
		//System.out.println("solving");
		int n = a.length - 1;
		long[] sum = new long[n + 1];
		a[0] = 0;
		sum[0] = 0;
		for(int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		Set<Long> after = new TreeSet<Long>();
		boolean valid = false;
		for(int i = n; i >= 0; i--) {
			
			if((sum[n] - 2 * sum[i]) % 2 == 0) {
				//System.out.println("on " + i + " looking for " + (sum[n] - 2 * sum[i]) / 2);
				if(after.contains((sum[n] - 2 * sum[i]) / 2)) {
					//System.out.println("on " + i + " got moving");
					valid = true;
				}
			}
			if(sum[i] == sum[n] - sum[i]) {
				//System.out.println("on " + i + " got not moving");
				valid = true;
			}
			after.add(a[i]);
		}
		return valid;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n + 1];
		long[] b = new long[n + 1];
		for(int i = 1; i <= n; i++) {
			a[i] = sc.nextLong();
			b[n - i + 1] = a[i];
		}
		
		boolean valid = solve(a) || solve(b);
		
		if(valid) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}