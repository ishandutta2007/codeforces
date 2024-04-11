import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int x = sc.nextInt();
			System.out.println((x-1) + " " + 1);
		}
	}
}