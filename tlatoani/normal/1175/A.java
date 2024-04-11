import java.util.Scanner;

public class ZeroToHero2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int c = 0; c < t; c++) {
            long n = scanner.nextLong();
            long k = scanner.nextLong();
            long amt = -1;
            for (long nTemp = n; nTemp > 0; nTemp /= k, amt++);
            while (n > 0) {
                amt += n % k;
                n /= k;
            }
            System.out.println(amt);
        }
    }
}