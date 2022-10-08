import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        long m = sc.nextLong();
        long[] xs = new long[n], ys = new long[n];
        long x0 = sc.nextInt(), y0 = sc.nextInt();
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextLong();
            ys[i] = sc.nextLong();
        }
        long ax = 1, bx = 0, ay = 1, by = 0;
        for (int i = 0; i < n; i++) {
            ax = -ax;
            bx = 2 * xs[i] - bx;
            ay = -ay;
            by = 2 * ys[i] - by;
        }
        BigInteger[][] X = {{valueOf(ax), valueOf(bx)}, {ZERO, ONE}};
        BigInteger[][] Y = {{valueOf(ay), valueOf(by)}, {ZERO, ONE}};
        X = pow(X, m / n);
        Y = pow(Y, m / n);
        BigInteger x = X[0][0].multiply(valueOf(x0)).add(X[0][1]);
        BigInteger y = Y[0][0].multiply(valueOf(y0)).add(Y[0][1]);
        for (int i = 0; i < m % n; i++) {
            x = valueOf(2 * xs[i]).subtract(x);
            y = valueOf(2 * ys[i]).subtract(y);
        }
        System.out.println(x + " " + y);
    }
    
    BigInteger[][] mul(BigInteger[][] a, BigInteger[][] b) {
        int n = a.length;
        BigInteger[][] c = new BigInteger[n][n];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) c[i][j] = ZERO;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    c[i][j] = (c[i][j].add(a[i][k].multiply(b[k][j])));
                }
            }
        }
        return c;
    }
    
    BigInteger[][] pow(BigInteger[][] a, long b) {
        int n = a.length;
        BigInteger[][] c = new BigInteger[n][n];
        for (int i = 0; i < n; i++) {
            fill(c[i], ZERO);
            c[i][i] = ONE;
        }
        while (b > 0) {
            if ((b & 1) != 0) c = mul(c, a);
            a = mul(a, a);
            b >>>= 1;
        }
        return c;
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