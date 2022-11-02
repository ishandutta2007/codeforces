import java.io.InputStreamReader;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            if (n < 3)
                System.out.println("0");
            else
                System.out.println((n - 1) / 2);
        }
    }
}