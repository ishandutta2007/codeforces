import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			long ans = 0;
			ans = (long) d*Math.min(a,b);
			ans+=(long) c*Math.abs(a-b);
			long comp = (long) c*(a+b);
			System.out.println(Math.min(ans,comp));
		}
	}
}