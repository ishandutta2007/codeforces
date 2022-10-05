import java.io.PrintStream;
import java.util.*;

public class SphereTransmission {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        long n = in.nextLong();
        double sqrtN = Math.sqrt(n);
        Set<Long> funValues = new TreeSet<>();
        for (long f = 1; f <= sqrtN + 1; f++) {
            if (n % f == 0) {
                long g = n / f;
                funValues.add(((f * g * (g - 1)) >> 1) + g);
                funValues.add(((g * f * (f - 1)) >> 1) + f);
            }
        }
        boolean isFirst = true;
        for (long funValue : funValues) {
            if (!isFirst) {
                out.print(" ");
            }
            out.print(funValue);
            isFirst = false;
        }
        out.println();
    }
}