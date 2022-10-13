import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] stonesOne = new int[n];
		int [] stonesTwo = new int[n];
		for (int i=0;i<n;i++) {
			stonesOne[i] = sc.nextInt();
		}
		for (int i=0;i<n;i++) {
			stonesTwo[i] = sc.nextInt();
		}
		int sum1=0;
		for (int i=0;i<n;i++) {
			sum1+=stonesOne[i];
		}
		int sum2=0;
		for (int i=0;i<n;i++) {
			sum2+=stonesTwo[i];
		}
		if ((sum1-sum2) >=0) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");

		}



	}
}