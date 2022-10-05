import java.math.BigInteger;
import java.util.Scanner;

public class RoundCorridor2 {

    static long readPosition(Scanner in, long ng, long mg) {
        if (in.nextInt() == 1) {
            return (in.nextLong() - 1L) / ng;
        } else {
            return (in.nextLong() - 1L) / mg;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long m = in.nextLong();
        long g = BigInteger.valueOf(n).gcd(BigInteger.valueOf(m)).longValueExact();
        long ng = n / g;
        long mg = m / g;
        for (long q = in.nextLong(); q > 0; q--) {
            long s = readPosition(in, ng, mg);
            long e = readPosition(in, ng, mg);
            System.out.println(s == e ? "YES" : "NO");
        }
    }
}