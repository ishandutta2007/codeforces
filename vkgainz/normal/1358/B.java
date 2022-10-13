import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int [] a = new int[n];
			for(int i=0;i<n;i++) {
				a[i] = sc.nextInt();
			}
			Arrays.sort(a);
			for(int i=0;i<n;i++) {
				a[i] = a[i]-(i+1);
			}
			int best = -1;
			for(int i=0;i<n;i++) {
				if(a[i]<=0) {
					best = i;
				}
			}
			System.out.println(best+2);
		}
	}
}