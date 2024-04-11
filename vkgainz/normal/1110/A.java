import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int b = sc.nextInt();
		int k = sc.nextInt();
		int a[] = new int[k];
		int sum =0;
		for(int i=0;i<k;i++) {
			a[i] = sc.nextInt();
			sum+=a[i];
		}
		if(b%2==0) {
			if(a[k-1]%2==1) {
				System.out.println("odd");
			}
			else {
				System.out.println("even");
			}
		}
		else {
			if(sum%2==1) {
				System.out.println("odd");
			}
			else {
				System.out.println("even");
			}
		}
		
	}
}