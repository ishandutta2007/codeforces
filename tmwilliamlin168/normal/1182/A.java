import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		if(n % 2 == 1)
			System.out.println(0);
		else
			System.out.println((int)Math.pow(2, n / 2));
	}
	
}