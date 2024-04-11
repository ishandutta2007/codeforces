import java.util.*;

public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int z = sc.nextInt();
		//find gcd
		int gcd =1;
		for (int i=1;i<=m;i++) {
			if (n*i%m==0) {
				gcd=n*i;
				break;
			}
		}
		System.out.println(z/gcd);
		
	}
	
}