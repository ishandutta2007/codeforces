import java.util.*;
 
public class Cmohamed {
    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    public static void main(String args[]) {
        int t;
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        while(--t >= 0) {
            long a, b;
            a = in.nextLong();
            b = in.nextLong();
            String answer = (gcd(a, b) == 1) ? "Finite" : "Infinite";
            System.out.println(answer);
        }
    }
}