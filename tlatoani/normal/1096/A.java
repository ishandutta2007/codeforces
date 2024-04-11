import java.io.*;
import java.util.Scanner;

public class FindDivisible {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int l = in.nextInt();
            in.nextInt();
            out.println(l + " " + (l << 1));
        }
    }
}