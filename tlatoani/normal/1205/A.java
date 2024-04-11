import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class AlmostEqual {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        if (n % 2 == 0) {
            out.println("NO");
            out.flush();
            out.close();
            return;
        }
        out.println("YES");
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                out.print(i << 1);
            } else {
                out.print((i << 1) - 1);
            }
            out.print(" ");
        }
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                out.print((i << 1) - 1);
            } else {
                out.print(i << 1);
            }
            if (i < n) {
                out.print(" ");
            }
        }
        out.println();
        out.flush();
        out.close();
    }
}