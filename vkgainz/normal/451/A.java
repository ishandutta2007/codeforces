import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long d = sc.nextLong();
		long min = Math.min(n, d);
		if (min%2==0) {
			System.out.println("Malvika");
		}
		else {
			System.out.println("Akshat");
		}
	}
}