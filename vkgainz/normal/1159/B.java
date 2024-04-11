import java.util.Scanner;

public class ExpansionCoefficient {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [] values = new int[n];
		for(int i=0;i<n;i++) {
			values[i] = sc.nextInt();
		}
		int [] pos = new int[n];
		int min = Integer.MAX_VALUE;
		for(int i=0;i<n;i++) {
			pos[i] = values[i]/(Math.max(n-i-1, i));
			min = Math.min(min, pos[i]);
		}
		System.out.println(min);
	}
}