import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int summation = 0;
		int[] count = new int[2];
		for (int i = 0; i < n; i++) {
			int input = in.nextInt();
			count[input & 1]++;
			summation += input;
		}
		System.out.println(count[summation & 1]);
	}
}