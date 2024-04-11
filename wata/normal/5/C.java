import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[] cs = sc.next().toCharArray();
        int n = cs.length;
        int[] is = new int[n + 1];
        for (int i = 0; i < n; i++) is[i + 1] = (cs[i] == '(') ? 1 : -1;
        for (int i = 0; i < n; i++) is[i + 1] += is[i];
        int max = 0, num = 1;
        int[] stack = new int[n + 2];
        int sp = 0;
        for (int i = 0; i <= n; i++) {
            int j = i;
            while (sp > 0 && is[stack[sp - 1]] >= is[i]) {
                if (is[stack[sp - 1]] == is[i]) {
                    if (max < i - stack[sp - 1]) {
                        max = i - stack[sp - 1];
                        num = 1;
                    } else if (max == i - stack[sp - 1]) {
                        num++;
                    }
                    j = stack[sp - 1];
                }
                sp--;
            }
            stack[sp++] = j;
        }
        System.out.printf("%d %d%n", max, num);
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
//              System.setIn(new FileInputStream("in.txt"));
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