import java.io.PrintStream;
import java.util.Scanner;

public class ChristmasOrnament {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int y = in.nextInt();
        int b = in.nextInt();
        int r = in.nextInt();
        out.println(3 * Math.min(b, Math.min(r - 1, y + 1)));
    }
}