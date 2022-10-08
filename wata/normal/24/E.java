import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        double[] xs = new double[n], vs = new double[n];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextDouble();
            vs[i] = sc.nextDouble();
        }
        double left = 0, right = 1e10;
        for (int r = 0; r < 100; r++) {
            double t = (left + right) / 2;
            double max = Double.NEGATIVE_INFINITY;
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                double x = xs[i] + vs[i] * t;
                if (vs[i] < 0) {
                    if (max > x) {
                        ok = false;
                        break;
                    }
                } else {
                    if (max < x) max = x;
                }
            }
            if (ok) left = t;
            else right = t;
        }
        if (left > 5 * 1e9) System.out.println(-1);
        else System.out.printf("%.15f", left);
    }
    
    class Scanner {
        BufferedReader br;
        StringTokenizer st;
        Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            eat("");
        }
        void eat(String s) {
            st = new StringTokenizer(s);
        }
        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        boolean hasNext() {
            while (!st.hasMoreTokens()) {
                String s = nextLine();
                if (s == null) return false;
                eat(s);
            }
            return true;
        }
        String next() {
            hasNext();
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        if (LOCAL) {
            try {
                System.setIn(new FileInputStream("in.txt"));
            } catch (Throwable e) {
                LOCAL = false;
            }
        }
        if (!LOCAL) {
            try {
                System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
            } catch (Throwable e) {
            }
        }
        new Main().run();
        System.out.flush();
    }
}