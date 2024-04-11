import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;//System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        int[][] g = new int[n][n];
        for (int i = 0; i < n; i++) fill(g[i], -1);
        for (int i = 0; i < n; i++) {
            int from = sc.nextInt() - 1, to = sc.nextInt() - 1, cost = sc.nextInt();
            g[from][to] = 0;
            g[to][from] = cost;
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) if (g[0][i] >= 0) {
            int prev = 0;
            int crt = i;
            int cost = g[0][i];
            while (crt != 0) {
                for (int j = 0; j < n; j++) if (j != prev && g[crt][j] >= 0) {
                    cost += g[crt][j];
                    prev = crt;
                    crt = j;
                    break;
                }
            }
            res = min(res, cost);
        }
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