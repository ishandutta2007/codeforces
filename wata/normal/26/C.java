import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;//System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        n = sc.nextInt();
        m = sc.nextInt();
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        res = new char[n][m];
        if (solve(n, m, a, b, c)) {
            for (int i = 0; i < res.length; i++) {
                System.out.println(res[i]);
            }
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
    
    boolean solve(int n, int m, int a, int b, int c) {
        if (n % 2 != 0) {
            if (m % 2 != 0) return false;
            for (int i = 0; i < m; i += 2) {
                if (--a < 0) return false;
                put(n - 1, n - 1, i, i + 1);
            }
            n--;
        } else if (m % 2 != 0) {
            for (int i = 0; i < n; i += 2) {
                if (--b < 0) return false;
                put(i, i + 1, m - 1, m - 1);
            }
            m--;
        }
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
                if (a >= 2) {
                    a -= 2;
                    put(i, i, j, j + 1);
                    put(i + 1, i + 1, j, j + 1);
                } else if (b >= 2) {
                    b -= 2;
                    put(i, i + 1, j, j);
                    put(i, i + 1, j + 1, j + 1);
                } else if (c >= 1) {
                    c--;
                    put(i, i + 1, j, j + 1);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
    int n, m;
    char[][] res;
    boolean[] used = new boolean[256];
    void put(int x1, int x2, int y1, int y2) {
        for (int i = 0; i < 26; i++) used['a' + i] = false;
        if (x1 - 1 >= 0) used[res[x1 - 1][y1]] = used[res[x1 - 1][y2]] = true;
        if (x2 + 1 < n) used[res[x2 + 1][y1]] = used[res[x2 + 1][y2]] = true;
        if (y1 - 1 >= 0) used[res[x1][y1 - 1]] = used[res[x2][y1 - 1]] = true;
        if (y2 + 1 < m) used[res[x1][y2 + 1]] = used[res[x2][y2 + 1]] = true;
        for (int i = 0; i < 26; i++) if (!used['a' + i]) {
            for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    res[x][y] = (char)('a' + i);
                }
            }
            return;
        }
        throw new RuntimeException();
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