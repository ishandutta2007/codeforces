import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;

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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            TaskD.Number a[] = new TaskD.Number[n];
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                a[i] = new TaskD.Number(x, i, x % m);
            }

            Arrays.sort(a, Comparator.comparing(o -> o.r));

            int ans[] = new int[n];
            long sumCost = 0;
            int l = 0, r = n - 1;
            for (int i = 0; i < n; ++i) {
                int x = i / (n / m);
                int pos = -1, cost = -1;
                if (a[l].r <= x) {
                    cost = x - a[l].r;
                    pos = l++;
                } else {
                    cost = m - (a[r].r - x);
                    pos = r--;
                }
                ans[a[pos].id] = a[pos].x + cost;
                sumCost += cost;
            }

            out.println(sumCost);
            for (int i = 0; i < n; ++i)
                out.printf("%d ", ans[i]);
        }

        public static class Number {
            int x;
            int id;
            int r;

            public Number(int x, int id, int r) {
                this.x = x;
                this.id = id;
                this.r = r;
            }

        }

    }
}