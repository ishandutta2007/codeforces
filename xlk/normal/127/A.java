import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] x = new int[n], y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		double z = 0;
		for (int i = 1; i < n; i++)
			z += Math.sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1])
					+ (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
		z /= 50.;
		z *= k;
		System.out.println(z);
	}
}