import java.io.PrintStream;
import java.util.Scanner;

public class SquaresAndSegments {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        long n = in.nextLong();
        long sqrt = (long) Math.ceil(Math.sqrt(n));
        if ((sqrt * (sqrt - 1)) >= n) {
            out.println(sqrt + sqrt - 1);
        } else {
            out.println(sqrt + sqrt);
        }
    }
}