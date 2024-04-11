import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.FileReader;
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
        B2Monitoring solver = new B2Monitoring();
        solver.solve(1, in, out);
        out.close();
    }

    static class B2Monitoring {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            Map<Integer, Integer> haveHorW = new HashMap<>();
            Map<Long, Integer> haveHandW = new HashMap<>();
            long ans = 0;
            for (int i = 0; i < n; i++) {
                int h = in.nextInt(), w = in.nextInt();
                if (h > w) {
                    int tmp = h;
                    h = w;
                    w = tmp;
                }
                int ansH = haveHorW.getOrDefault(h, 0);
                int ansW = haveHorW.getOrDefault(w, 0);
                int haveHW = haveHandW.getOrDefault(((long) h << 30) | w, 0);
                if (h == w) {
                    ans += ansH;
                    haveHorW.put(h, ansH + 1);
                } else {
                    ans += ansH + ansW - haveHW;
                    haveHorW.put(h, ansH + 1);
                    haveHorW.put(w, ansW + 1);
                    haveHandW.put(((long) h << 30) | w, haveHW + 1);
                }
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

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
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}