import java.io.InputStreamReader;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            int ans1 = Math.max(a, b * 2);
            int ans2 = Math.max(b, a * 2);

            int ans = Math.min(ans1, ans2);
            System.out.println(ans * ans);
        }
    }
}