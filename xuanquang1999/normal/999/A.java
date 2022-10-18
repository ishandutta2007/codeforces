import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author xuanquang1999
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = in.nextInt();

            int l = 0, r = n - 1;
            while (l <= r && a[l] <= k) ++l;
            while (l <= r && a[r] <= k) --r;
            out.println(n - (r - l + 1));
        }

    }
}