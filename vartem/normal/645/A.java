import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        String a = in.nextToken() + new StringBuilder(in.nextToken()).reverse();
        String b = in.nextToken() + new StringBuilder(in.nextToken()).reverse();
        a = a.replace("X", "");
        b = b.replace("X", "");

        for (int i = 0; i < 3; i++) {
            String s = b.substring(i) + b.substring(0, i);
            if (a.equals(s)) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new A().run();
    }
}