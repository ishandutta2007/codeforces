import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            long a = scanner.nextInt();
            long b = scanner.nextInt();
            long x = scanner.nextInt();
            long y = scanner.nextInt();
            long n = scanner.nextInt();

            if (a + b - x - y <= n) {
                System.out.println(x * y);
                continue;
            }

            long n1 = 0, n2 = 0;
            if (a - n >= x) {
                n1 = (a - n) * b;
            } else {
                n1 = x * (b - n + (a - x));
            }

            if (b - n >= y) {
                n2 = a * (b - n);
            } else {
                n2 = (y * (a - n + (b - y)));
            }
            //System.out.printf("%d %d", n1, n2);
            System.out.println(Math.min(n1, n2));
        }
    }
}