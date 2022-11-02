import java.io.InputStreamReader;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();

            int ans = Integer.MAX_VALUE;
            for (int j = 1; j < Math.sqrt(n) + 5; j++) {
                if (n % j == 0) {
                    int ans1 = j;
                    int ans2 = n / j;
                    if (ans1 <= k)
                        ans = Math.min(ans, ans2);

                    if (ans2 <= k)
                        ans = Math.min(ans, ans1);
                }
            }

            System.out.println(ans);

        }
    }
}