import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		int N = sc.nextInt();
		int K = sc.nextInt();
		PrintWriter writer = new PrintWriter(System.out);
		writer.println(K * (5 + (N - 1) * 6));
		for (int i = 0; i < N; ++i) {
			int base = 1 + i * 6;
			writer.print(base * K);
			writer.print(" ");
			writer.print((base + 1) * K);
			writer.print(" ");
			writer.print((base + 2) * K);
			writer.print(" ");
			writer.print((base + 4) * K);
			writer.println();
		}
		writer.flush();
	}

}