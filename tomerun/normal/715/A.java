import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		long cur = 2;
		StringBuilder sb = new StringBuilder();
		for (long i = 1; i <= N; ++i) {
			long v = cur / i;
			long mul = (i + 1) * (i + 1) * i;
			long target = 1;
			while (mul * target * target < v) {
				++target;
			}
			sb.append(mul * target * target - v);
			sb.append("\n");
			cur = i * (i + 1) * target;
		}
		System.out.print(sb);
	}

}