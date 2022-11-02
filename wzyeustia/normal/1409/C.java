import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int j = 0; j < t; j++) {
            long n = scanner.nextInt();
            long x = scanner.nextInt();
            long y = scanner.nextInt();

            long crtMax = Long.MAX_VALUE;
            long crtI = -1;
            boolean left = false;
            for (long i = n; i >= 2; i--) {
                long divisor = (y - x) / (i - 1);
                if ((y - x) % (i - 1) == 0) {
                    long beforeLength = (y - 1) / divisor;
                    if (beforeLength >= n - 1) {
                        crtMax = y;
                        crtI = i;
                        left = true;
                        break;
                    } else {
                        long thisMax = y + (n - 1 - beforeLength) * divisor;
                        if (thisMax < crtMax) {
                            crtMax = thisMax;
                            crtI = i;
                        }
                    }
                }
            }

            long divisor = (y - x) / (crtI - 1);
            if (left) {
                for (long i = 0; i < n; i++) {
                    System.out.print(y - i * divisor);
                    System.out.print(' ');
                }
                System.out.println();
            } else {
                long start = y % divisor;
                if (start == 0)
                    start = divisor;
                for (long i = 0; i < n; i++) {
                    System.out.print(start + i * divisor);
                    System.out.print(' ');
                }
                System.out.println();
            }

        }
    }
}