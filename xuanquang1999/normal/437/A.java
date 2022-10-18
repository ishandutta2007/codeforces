import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
            int[] len = new int[4];
            for (int i = 0; i < 4; ++i) {
                String s = in.nextLine();
                len[i] = s.length() - 2;
            }

            char ans = 'C';
            int cntGreat = 0;
            for (int i = 0; i < 4; ++i) {
                boolean allShorter = true;
                boolean allLonger = true;
                for (int j = 0; j < 4; ++j) {
                    if (i != j) {
                        if (len[i] * 2 > len[j]) {
                            allShorter = false;
                        }
                        if (len[i] < len[j] * 2) {
                            allLonger = false;
                        }
                    }
                }

                if (allShorter || allLonger) {
                    ++cntGreat;
                    ans = (char) ((int) 'A' + i);
                }
            }

            if (cntGreat > 1) {
                ans = 'C';
            }
            System.out.println(ans);
        }

    }
}