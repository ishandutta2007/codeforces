import java.io.PrintStream;
import java.util.Scanner;

public class PermutationConcatenation {
    static final long MOD = 998244353;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        long n = in.nextInt();
        long sum = 0;
        long addend = 1;
        for (long k = n; k > 1; k--) {
            addend *= k;
            addend %= MOD;
            sum += addend;
            sum %= MOD;
        }
        sum = n * addend - sum;
        sum %= MOD;
        out.println(sum);
    }
}