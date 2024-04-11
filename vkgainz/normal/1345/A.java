import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int m= sc.nextInt();
			if(Math.min(n,m)==1) {
				System.out.println("YES");
			}
			else if(n==m && n==2) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}
}