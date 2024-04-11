import java.io.PrintStream;
import java.util.Scanner;

public class CombinationLock {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int n = in.nextInt();
        int[] rotations = new int[n];
        for (int i = 0; i < n; i++) {
            rotations[i] = in.nextInt();
        }
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) == 0) {
                    sum += rotations[k];
                } else {
                    sum -= rotations[k];
                }
            }
            if (sum % 360 == 0) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }
}