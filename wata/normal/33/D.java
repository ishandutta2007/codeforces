import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
        int[] xs = new int[n], ys = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextInt();
            ys[i] = sc.nextInt();
        }
        int[] cx = new int[m], cy = new int[m], rs = new int[m];
        for (int i = 0; i < m; i++) {
            rs[i] = sc.nextInt();
            cx[i] = sc.nextInt();
            cy[i] = sc.nextInt();
        }
        boolean[][] in = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                in[i][j] = sq(xs[i] - cx[j]) + sq(ys[i] - cy[j]) < sq(rs[j]);
            }
        }
        for (int i = 0; i < k; i++) {
            int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
            int res = 0;
            for (int j = 0; j < m; j++) if (in[a][j] != in[b][j]) res++;
            System.out.println(res);
        }
    }
    
    long sq(long x) {
        return x * x;
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