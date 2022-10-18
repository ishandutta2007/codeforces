import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            ArrayList<Integer> pos[] = new ArrayList[26];
            for (int c = 0; c < 26; ++c)
                pos[c] = new ArrayList<>();

            String s = in.next();
            for (int i = 0; i < n; ++i)
                pos[s.charAt(i) - 'a'].add(i);

            boolean avail[] = new boolean[n];
            for (int i = 0; i < n; ++i)
                avail[i] = true;

            int cnt = 0;
            for (int c = 0; c < 26; ++c) {
                for (int x : pos[c]) {
                    if (cnt == k)
                        break;
                    avail[x] = false;
                    ++cnt;
                }
            }


            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; ++i)
                if (avail[i]) sb.append(s.charAt(i));
            out.println(sb.toString());
        }

    }
}