import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int ans = n*m+1;
			ans/=2;
			System.out.println(ans);
		}
	}
}