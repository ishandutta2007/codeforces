import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Comparator;
import java.util.Collections;
import java.util.ArrayList;

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
            ArrayList<Number> a = new ArrayList<>();
            int n = in.nextInt();
            for (int i = 0; i < n; ++i) {
                long x = in.nextLong();
                a.add(new Number(x));
            }

            Collections.sort(a, new Comparator<Number>() {
                public int compare(Number a, Number b) {
                    if (a.p3 > b.p3) return -1;
                    if (a.p3 < b.p3) return 1;
                    if (a.p2 < b.p2) return -1;
                    return 1;
                }
            });

            for (Number num : a) System.out.print(num.x + " ");
        }

        public class Number {
            long x;
            int p2;
            int p3;

            Number(long x) {
                this.x = x;

                p2 = 0;
                while (x % 2 == 0) {
                    x /= 2;
                    ++p2;
                }

                p3 = 0;
                while (x % 3 == 0) {
                    x /= 3;
                    ++p3;
                }
            }

        }

    }
}