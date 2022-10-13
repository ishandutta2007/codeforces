import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		if(n==1) System.out.println(1);
		else{
		if(n%2==0){
			if(m>n/2) {
				System.out.println(m-1);
			}
			else if(m<=n/2) {
				System.out.println(m+1);
			}
			
		}
		else{
			if(m>=(n+1)/2) {
				System.out.println(m-1);
			}
			else if(m<(n+1)/2) {
				System.out.println(m+1);
			}
		
		}
		}
	}
}