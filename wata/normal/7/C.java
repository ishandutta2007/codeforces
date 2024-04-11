import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        long a = sc.nextLong(), b = sc.nextLong(), c = sc.nextLong();
        long[] gcd = exgcd(a, b);
        if (c % gcd[2] != 0) {
            System.out.println(-1);
        } else {
            System.out.printf("%d %d%n", -gcd[0] * (c / gcd[2]), -gcd[1] * (c / gcd[2]));
        }
    }
    
    //ax+by=gcd(x,y){a,b,c=gcd(x,y)}
    //(a,b)(a+d*y/c,b-d*x/c)
    long[] exgcd(long x, long y) {
        long a0 = 1, a1 = 0, b0 = 0, b1 = 1, t;
        while (y != 0) {
            t = a0 - x / y * a1; a0 = a1; a1 = t;
            t = b0 - x / y * b1; b0 = b1; b1 = t;
            t = x % y; x = y; y = t;
        }
        if (x < 0) {
            a0 = -a0; b0 = -b0; x = -x;
        }
        return new long[] {a0, b0, x};
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