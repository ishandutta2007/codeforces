import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] presents = new int[n];
		for (int i=0;i<n;i++) {
			presents[i] = sc.nextInt();
		}
		Arrays.sort(presents);
		int max = presents[n-1];
		int sum=0;
		for (int i=0;i<n;i++) {
			sum+=max-presents[i];
		}
		System.out.println(sum);
	}
}