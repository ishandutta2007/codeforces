import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int sx = sc.nextInt();
            long sy = sc.nextLong();
            int ex = sc.nextInt();
            long ey = sc.nextLong();
 
            boolean success = solve(n, m, sx, sy, ex, ey);
            System.out.println(success ? "YES" : "NO");
        }
    }
 
    private static boolean solve(long n, long m, int sx, long sy, int ex, long ey) {
        long gcdvalue = gcd(n, m);
        long lcmvalue = n / gcdvalue * m;
 
        long wallfactor = lcmvalue / gcdvalue;
 
        if (sx == 1) {
            sy = lcmvalue / n * sy;
        } else {
            sy = lcmvalue / m * sy;
        } 
        if (ex == 1) {
            ey = lcmvalue / n * ey;
        } else {
            ey = lcmvalue / m * ey;
        }
 
        return (sy-1) / wallfactor == (ey-1) / wallfactor;
    }
 
    private static long lcm(long n, long m) {
        return n / gcd(n, m) * m;
    }
 
    private static long gcd(long n, long m) {
        if (n < m) {
            long tmp = n;
            n = m;
            m = tmp;
        }
        if (m == 0) {
            return n;
        }
        return gcd(m, n % m);
    }
}