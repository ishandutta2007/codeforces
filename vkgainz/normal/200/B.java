import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double n = sc.nextInt();
		int sum=0;
		for (int i=0;i<n;i++) {
			sum+=sc.nextInt();
		}
		double asdf = sum/n;
		System.out.println(asdf);  

	}
}