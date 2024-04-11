import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n%2 ==0) {
			System.out.println(4);
			System.out.println(n-4);
		}
		else {
			System.out.println(9);
			System.out.println(n-9);
		}
		
		
	}
}