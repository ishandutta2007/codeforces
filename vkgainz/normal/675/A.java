import java.util.*;

public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		if (c !=0) {
		if ((b-a)%c == 0 && (b-a)/c >= 0) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
		}
		else {
			if (a==b) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}
	
}