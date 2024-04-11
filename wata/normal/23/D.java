import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    double EPS = 1e-10;
    
    void run() {
        int t = sc.nextInt();
        loop : while (t-- > 0) {
            P[] ps = new P[3];
            for (int i = 0; i < 3; i++) ps[i] = new P(sc.nextDouble(), sc.nextDouble());
            int[] is = new int[3];
            for (int i = 0; i < 3; i++) is[i] = i;
            do {
                P p3 = ps[is[0]].mul(2).sub(ps[is[1]]);
                P p4 = ps[is[2]].sub(ps[is[1]].mul(2)).add(ps[is[0]].mul(2));
                P[] qs = new P[4];
                qs[0] = ccenter(ps[is[0]], p3, p4);
                if (qs[0] != null) {
                    for (int i = 0; i < 3; i++) qs[i + 1] = ps[is[i]].mul(2).sub(qs[i]);
                    boolean ok = true;
                    for (int i = 0; i < 4; i++) {
                        if (qs[(i + 1) % 4].sub(qs[i]).det(qs[(i + 2) % 4].sub(qs[i])) < EPS) ok = false;
                    }
                    if (ok) {
                        System.out.println("YES");
                        System.out.printf("%.9f %.9f %.9f %.9f %.9f %.9f %.9f %.9f%n", qs[0].x, qs[0].y, qs[1].x, qs[1].y, qs[2].x, qs[2].y, qs[3].x, qs[3].y);
                        continue loop;
                    }
                }
            } while (nextPermutation(is));
            System.out.println("NO");
            System.out.println();
        }
    }
    
    P ccenter(P A, P B, P C) {
        P AB = B.sub(A), BC = C.sub(B), CA = A.sub(C);
        if (abs(AB.det(BC)) < EPS) return null;
        return A.add(B).sub(AB.rot90().mul(BC.dot(CA)).div(AB.det(BC))).div(2);
    }
    
    boolean nextPermutation(int[] is) {
        int n = is.length;
        for (int i = n - 1; i > 0; i--) {
            if (is[i - 1] < is[i]) {
                int j = n;
                while (is[i - 1] >= is[--j]);
                swap(is, i - 1, j);
                rev(is, i, n);
                return true;
            }
        }
        rev(is, 0, n);
        return false;
    }
    void swap(int[] is, int i, int j) {
        int t = is[i]; is[i] = is[j]; is[j] = t;
    }
    void rev(int[] is, int s, int t) {
        while (s < --t) swap(is, s++, t);
    }
    
    class P {
        double x, y;
        P(double x, double y) {
            this.x = x;
            this.y = y;
        }
        P add(P p) {
            return new P(x + p.x, y + p.y);
        }
        P sub(P p) {
            return new P(x - p.x, y - p.y);
        }
        P mul(double d) {
            return new P(x * d, y * d);
        }
        P div(double d) {
            return new P(x / d, y / d);
        }
        double dot(P p) {
            return x * p.x + y * p.y;
        }
        double det(P p) {
            return x * p.y - y * p.x;
        }
        double abs() {
            return sqrt(abs2());
        }
        double abs2() {
            return x * x + y * y;
        }
        P rot90() {
            return new P(-y, x);
        }
        public String toString() {
            return String.format("(%.2f, %.2f)", x, y);
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
                Locale.setDefault(Locale.US);
                System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
            } catch (Throwable e) {
            }
        }
        new Main().run();
        System.out.flush();
    }
}