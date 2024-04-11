import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[][] cs = new char[8][];
        for (int i = 0; i < 8; i++) {
            cs[i] = sc.next().toCharArray();
        }
        int res = 100;
        for (int i = 0; i < 1 << 16; i++) {
            char[][] ds = new char[8][8];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    ds[j][k] = 'W';
                }
            }
            int num = 0;
            for (int j = 0; j < 8; j++) {
                if ((i >> j & 1) != 0) {
                    num++;
                    for (int k = 0; k < 8; k++) {
                        ds[j][k] = 'B';
                    }
                }
                if ((i >> (8 + j) & 1) != 0) {
                    num++;
                    for (int k = 0; k < 8; k++) {
                        ds[k][j] = 'B';
                    }
                }
            }
            boolean ok = true;
            for (int j = 0; j < 8; j++) ok &= Arrays.equals(cs[j], ds[j]);
            if (ok) res = min(res, num);
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
                Locale.setDefault(Locale.US);
                System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
            } catch (Throwable e) {
            }
        }
        new Main().run();
        System.out.flush();
    }
}