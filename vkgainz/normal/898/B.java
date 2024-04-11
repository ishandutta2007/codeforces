import java.util.*;
public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long a = sc.nextLong();
		long b= sc.nextLong();
		int posA=0;
		int posB=0;
		boolean isDiv=false;
		for (int i=0;i<=n/b;i++) {
			if((n-b*i)%a==0) {
				posA= (int) ((n-b*i)/a);
				posB=i;
				isDiv=true;
				break;
				
			}
		}
		if (isDiv) {
			System.out.println("YES");
			System.out.println(posA);
			System.out.println(posB);
		}
		else System.out.println("NO");
		
}
	
}