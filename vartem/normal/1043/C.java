import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next();

            int n = s.length();
            String[] min = new String[n + 1], minRev = new String[n + 1];
            int[] move = new int[n + 1], moveRev = new int[n + 1];
            min[0] = minRev[0] = "";
            for (int i = 0; i < n; i++) {
                {
                    String s1 = min[i] + s.charAt(i), s2 = s.charAt(i) + reverse(minRev[i]);
                    if (s1.compareTo(s2) < 0) {
                        min[i + 1] = s1;
                        move[i + 1] = 0;
                    } else {
                        min[i + 1] = s2;
                        move[i + 1] = 1;
                    }
                }
                {
                    String s1 = minRev[i] + s.charAt(i), s2 = s.charAt(i) + reverse(min[i]);
                    if (reverse(s1).compareTo(reverse(s2)) < 0) {
                        minRev[i + 1] = s1;
                        moveRev[i + 1] = 0;
                    } else {
                        minRev[i + 1] = s2;
                        moveRev[i + 1] = 1;
                    }
                }
            }


            int curRev = 0;
            int[] ans = new int[n];
            for (int i = n; i > 0; i--) {
                if (curRev == 0) {
                    ans[i - 1] = move[i];
                } else {
                    ans[i - 1] = moveRev[i];
                }
                if (ans[i - 1] == 1) {
                    curRev ^= 1;
                }
            }
            Utils.printArray(out, ans);
        }

        private String reverse(String s1) {
            return new StringBuilder(s1).reverse().toString();
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }

    static class Utils {
        public static void printArray(PrintWriter out, int[] a) {
            for (int i = 0; i < a.length; i++) {
                out.print(a[i]);
                if (i + 1 == a.length) {
                    out.println();
                } else {
                    out.print(' ');
                }
            }
        }

    }
}