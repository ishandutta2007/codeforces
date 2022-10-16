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
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt();
                char[] s = in.next().toCharArray();
                boolean found = false;
                for (int start2 = 1; start2 <= 9; start2++) {
                    int last1 = 0, last2 = start2;
                    boolean ok = true;
                    for (int i = 0; i < s.length; i++) {
                        int c = s[i] - '0';
                        if (last2 > c) {
                            ok &= last1 <= c;
                            last1 = c;
                        } else {
                            ok &= last2 <= c;
                            last2 = c;
                        }
                    }
                    ok &= last1 <= start2;
                    if (ok) {
                        found = true;

                        last1 = 0;
                        last2 = start2;
                        for (int i = 0; i < s.length; i++) {
                            int c = s[i] - '0';
                            if (last2 > c) {
                                out.print('1');
                            } else {
                                last2 = c;
                                out.print('2');
                            }
                        }
                        out.println();
                        break;
                    }
                }
                if (!found) {
                    out.println('-');
                }
            }
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

        public int nextInt() {
            return Integer.parseInt(next());
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
}