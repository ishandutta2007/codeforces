import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long d = sc.nextLong();
		if (n%2 ==0) {
			if (d <= n/2) {
				System.out.println(2*d-1);
			}
			else {
				System.out.println(2*d-n);
			}
		}
		else {
			if (d <= (n+1)/2) {
				System.out.println(2*d-1);
			}
			else {
				System.out.println(2*d-n-1);
			}
		}
	}
}