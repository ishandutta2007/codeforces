import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int X = sc.nextInt(), Y = sc.nextInt();
        int cx = sc.nextInt(), cy = sc.nextInt();
        double[] e = new double[Y];
        double[] diag = new double[Y];
        double[] sub = new double[Y];
        double[] sup = new double[Y];
        for (int x = X; x > cx; x--) {
            for (int i = 0; i < Y; i++) {
                if (i == 0 && Y == 1) {
                    diag[i] = 1;
                } else if (i == 0) {
                    diag[i] = 2;
                    sup[i] = -1;
                } else if (i + 1 == Y) {
                    diag[i] = 2;
                    sub[i - 1] = -1;
                } else {
                    diag[i] = 3;
                    sub[i - 1] = -1;
                    sup[i] = -1;
                }
                if (i == 0 && Y == 1) {
                    e[i] += 2;
                } else if (i == 0) {
                    e[i] += 3;
                } else if (i + 1 == Y) {
                    e[i] += 3;
                } else {
                    e[i] += 4;
                }
            }
            guess3(diag, sub, sup, e);
        }
        System.out.printf("%.10f%n", e[cy - 1]);
    }
    
    void guess3(double[] diag, double[] sub, double[] sup, double[] b) {
        int n = diag.length;
        for (int i = 0; i < n - 1; i++) {
            double t = sub[i] / diag[i];
            diag[i + 1] -= t * sup[i];
            b[i + 1] -= t * b[i];
        }
        b[n - 1] /= diag[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            b[i] = (b[i] - sup[i] * b[i + 1]) / diag[i];
        }
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