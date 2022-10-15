import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] a =new  int[4];
		for (int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		Arrays.sort(a);
		System.out.print((a[3]-a[0])+" "+(a[3]-a[1])+" "+(a[3]-a[2]));
	}
}