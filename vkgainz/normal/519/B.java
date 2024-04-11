import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] susOne = new int[n];
		for (int i=0;i<n;i++) {
			susOne[i] = sc.nextInt();
		}
		int [] susTwo = new int[n-1];
		for (int i=0;i<n-1;i++) {
			susTwo[i] = sc.nextInt();
		}
		int [] susThree = new int[n-2];
		for (int i=0;i<n-2;i++) {
			susThree[i] = sc.nextInt();
		}
		int sumOne =0;
		for (int i=0;i<n;i++) {
			sumOne+=susOne[i];
		}
		int sumTwo=0;
		for (int i=0;i<n-1;i++){
			sumTwo+=susTwo[i];
		}
		int sumThree=0;
		for (int i=0;i<n-2;i++) {
			sumThree+=susThree[i];
		}
		System.out.println(sumOne-sumTwo);
		System.out.println(sumTwo-sumThree);
}
}