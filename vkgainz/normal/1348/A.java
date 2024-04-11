import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t= sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int k = n/2;
			int ans = (int) (Math.pow(2,k+1)-2);
			System.out.println(ans);
		}
	}
}