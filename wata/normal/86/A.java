import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        long L = sc.nextInt(), R = sc.nextInt();
        long res = 0;
        for (long i = 10; i <= 10000000000L; i *= 10) {
            long L2 = max(i / 10, L), R2 = min(i - 1, R);
            if (L2 <= R2) {
                res = max(res, L2 * (i - 1 - L2));
                res = max(res, R2 * (i - 1 - R2));
                for (long j = i / 2 -1; j <= i / 2 + 1; j++) {
                    if (L2 <= j && j <= R2) {
                        res = max(res, j * (i - 1 - j));
                    }
                }
            }
        }
        System.out.println(res);
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new A().run();
    }
}