import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        int[] is = new int[n];
        for (int i = 0; i < n; i++) is[i] = sc.nextInt();
        int[] dp1 = new int[n + 1];
        int sum = 0, max = 0;
        for (int i = 0; i < n; i++) {
            sum -= is[i];
            max += is[i];
            if (max < sum) max = sum;
            dp1[i + 1] = max;
        }
        int[] dp2 = new int[n + 1];
        sum = 0; max = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum -= is[i];
            max += is[i];
            if (max < sum) max = sum;
            dp2[i] = max;
        }
        int res = Integer.MIN_VALUE;
        for (int i = 0; i <= n; i++) res = max(res, dp1[i] + dp2[i]);
        System.out.println(res);
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