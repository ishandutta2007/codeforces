import java.io.PrintStream;
import java.util.Scanner;

public class SubstringRemoval {
    static final int MOD = 998244353;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        in.nextLine();
        String string = in.nextLine();
        long n = string.length();
        char firstChar = string.charAt(0);
        long firstExtent = 0;
        for (; firstExtent < n && string.charAt((int) firstExtent) == firstChar; firstExtent++);
        firstExtent--;
        if (firstExtent == n - 1) {
            out.println(((n * ((n + 1)) >> 1) % MOD));
        }
        char lastChar = string.charAt((int) n - 1);
        long lastExtent = n - 1;
        for (; lastExtent >= 0 && string.charAt((int) lastExtent) == lastChar; lastExtent--);
        lastExtent++;
        if (firstChar != lastChar) {
            out.println((1 + firstExtent + 1 + n - lastExtent) % MOD);
        } else {
            out.println(((2 + firstExtent) * (1 + n - lastExtent)) % MOD);
        }
    }
}