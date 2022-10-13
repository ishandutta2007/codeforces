import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int a[] = new int[n];
			for(int i=0;i<n;i++) {
				a[i] = sc.nextInt();
			}
			int b[] = new int[n];
			int numOne = 0;
			for(int i=0;i<n;i++) {
				b[i] = sc.nextInt();
				numOne+=b[i];
			}
			if(numOne>0 && numOne<n) {
				System.out.println("Yes");
			}
			else {
				boolean sorted = true;
				for(int i=0;i<n-1;i++) {
					if(a[i]>a[i+1]) {
						sorted = false;
						break;
}
				}
				if(sorted) {
					System.out.println("Yes");
				}
				else {
					System.out.println("No");
				}
			}
		}
	}
}