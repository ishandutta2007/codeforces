import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            Integer[] arr = new Integer[n + 2];
            arr[0] = 1;
            arr[n + 1] = 1000000001;
            for (int i = 1; i <= n; ++i) arr[i] = in.nextInt();

            Arrays.sort(arr);

            if (arr[k].equals(arr[k + 1])) {
                out.println(-1);
            } else {
                out.println(arr[k]);
            }
        }

    }
}