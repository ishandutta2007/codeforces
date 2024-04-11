import java.util.*;

public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		if (a == 0 && b ==0) {
			System.out.println("NO");
		}
		else {
		if (Math.abs(a-b) <=1) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
		}
		
	}
	
}