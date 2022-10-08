import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;//System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[] cs = sc.next().toCharArray();
        int n = cs.length;
        int[] hs = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            if (cs[i] == ')') hs[i] = hs[i + 1] + 1;
            else hs[i] = hs[i + 1];
        }
        int res = 0;
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (cs[i] == '(' && hs[i + 1] >= h + 1) {
                h++;
                res++;
            } else if (cs[i] == ')' && h > 0) {
                h--;
                res++;
            }
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