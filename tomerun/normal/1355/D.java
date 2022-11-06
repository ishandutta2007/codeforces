import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static PrintWriter writer = new PrintWriter(System.out);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int S = sc.nextInt();
		if (N * 2 <= S) {
			writer.println("YES");
			for (int i = 0; i < N - 1; i++) {
				writer.print("2 ");
			}
			writer.println(S - 2 * (N - 1));
			writer.println(1);
		} else {
			writer.println("NO");
		}
		writer.flush();
	}
}