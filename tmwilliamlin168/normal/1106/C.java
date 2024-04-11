import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] arr = new int[n];
		for (int i=0;i<n;i++)arr[i]=scan.nextInt();
		Arrays.sort(arr);
		long ans = 0l;
		for (int i=0;i<n/2;i++) {
			ans+=Math.pow((long)arr[i]+arr[n-1-i],2);
		}
		System.out.println(ans);
		scan.close();
	}
}