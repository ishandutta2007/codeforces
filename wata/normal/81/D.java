import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class D {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt(), m = sc.nextInt();
        int[] a = new int[m + 1];
        for (int i = 0; i < m; i++) a[i] = sc.nextInt();
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (i > 0) prev = res[i - 1];
            int p = 0;
            if (prev == 0) p = 1;
            for (int j = 0; j < m; j++) if (j != prev && a[p] < a[j]) p = j;
            if (a[p] == 0) {
                System.out.println(-1);
                return;
            }
            res[i] = p;
            a[p]--;
        }
        if (res[n - 1] == res[0]) {
            for (int i = 0; i < m; i++) if (i != res[0] && i != res[n - 2] && a[i] > 0) {
                res[n - 1] = i;
                break;
            }
            if (res[n - 1] == res[0]) {
                if (res[n - 3] == res[0]) {
                    System.out.println(-1);
                    return;
                } else {
                    res[n - 1] = res[n - 2];
                    res[n - 2] = res[0];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(res[i] + 1);
        }
        System.out.println();
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new D().run();
    }
}