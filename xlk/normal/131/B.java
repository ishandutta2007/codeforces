import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] c = new int[30];
		for (int i = 0; i < n; i++)
			c[in.nextInt() + 10]++;
		long z = c[10] * (c[10] - 1L) / 2;
		for (int i = 1; i <= 10; i++)
			z += (long) c[10 + i] * c[10 - i];
		System.out.println(z);
	}
}