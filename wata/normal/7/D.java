import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[] cs = sc.nextLine().toCharArray();
        int n = cs.length;
        int[] pal = palindrome(cs);
        int[] deg = new int[n];
        long res = 0;
        for (int i = 0; i < n; i++) {
            if (pal[i] == i + 1) {
                deg[i] = deg[(i - 1) / 2] + 1;
            }
            res += deg[i];
        }
        System.out.println(res);
    }
    
    //
    //len[i]:i/2
    //:[a,b),[a,c),[b,d)[c,d)
    //O(n)
    int[] palindrome(char[] cs) {
        int n = cs.length;
        int[] len = new int[n * 2];
        for (int i = 0, j = 0, k; i < n * 2; i += k, j = max(j - k, 0)) {
            while (i - j >= 0 && i + j + 1 < n * 2 && cs[(i - j) / 2] == cs[(i + j + 1) / 2]) j++;
            len[i] = j;
            for (k = 1; i - k >= 0 && j - k >= 0 && len[i - k] != j - k; k++) {
                len[i + k] = min(len[i - k], j - k);
            }
        }
        return len;
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