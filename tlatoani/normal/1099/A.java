import java.io.PrintStream;
import java.util.Scanner;

public class Snowball {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int w = in.nextInt();
        int h = in.nextInt();
        int u1 = in.nextInt();
        int d1 = in.nextInt();
        int u2 = in.nextInt();
        int d2 = in.nextInt();
        int[] rocks = new int[h + 1];
        rocks[d1] = u1;
        rocks[d2] = u2;
        for (int y = h; y > 0; y--) {
            w += y;
            w = Math.max(0, w - rocks[y]);
        }
        out.println(w);
    }
}