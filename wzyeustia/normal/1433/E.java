import java.util.Scanner;

public class E {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        long ans = 1;
        for (int k = 1; k <= n / 2; k++) {
            ans *= (n + 1 - k);
            ans /= k;
        }

        for (int k = 1; k <= n / 2 - 1; k++) {
            ans *= k * k;
        }

        ans /= 2;
        System.out.println(ans);
    }
}