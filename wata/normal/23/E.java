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
        while (sc.hasNext()) {
            int n = sc.nextInt();
            V[] vs = new V[n];
            for (int i = 0; i < n; i++) vs[i] = new V();
            for (int i = 0; i < n - 1; i++) {
                int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
                vs[a].add(vs[b]);
                vs[b].add(vs[a]);
            }
            System.out.println(vs[0].dp(null)[0]);
            if (!LOCAL) return;
        }
    }
    
    int N = 710;
    
    class V extends ArrayList<V> {
        BigInteger[] dp(V prev) {
            BigInteger[] dp = new BigInteger[2];
            fill(dp, ZERO);
            dp[1] = ONE;
            for (V v : this) if (v != prev) {
                BigInteger[] dp3 = v.dp(this);
                BigInteger[] dp2 = new BigInteger[dp.length + dp3.length - 1];
                fill(dp2, ZERO);
                for (int i = 0; i < dp.length; i++) if (dp[i].signum() > 0) {
                    for (int j = 0; j < dp3.length; j++) if (dp3[j].signum() > 0) {
                        dp2[i + j] = dp2[i + j].max(dp[i].multiply(dp3[j]));
                    }
                }
                dp = dp2;
            }
            for (int i = 1; i < dp.length; i++) dp[0] = dp[0].max(valueOf(i).multiply(dp[i]));
            return dp;
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