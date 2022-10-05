import java.io.PrintStream;
import java.util.Scanner;

public class CardGame {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        String toMatch = in.next();
        for (int i = 0; i < 5; i++) {
            String card = in.next();
            if (card.charAt(0) == toMatch.charAt(0) || card.charAt(1) == toMatch.charAt(1)) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }
}