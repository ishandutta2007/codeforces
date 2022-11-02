import java.io.InputStreamReader;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int k = scanner.nextInt();

            int num = n / k;
            if (num >= m) {
                System.out.println(m);
            } else {
                System.out.println(num - (m - num + k - 2) / (k - 1));
            }
        }
    }
}