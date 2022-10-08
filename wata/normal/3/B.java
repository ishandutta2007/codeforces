import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt(), W = sc.nextInt();
        int[] vs1 = new int[n], vs2 = new int[n];
        int[] id1 = new int[n], id2 = new int[n];
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++) {
            if (sc.nextInt() == 1) {
                id1[n1] = i + 1;
                vs1[n1++] = sc.nextInt();
            } else {
                id2[n2] = i + 1;
                vs2[n2++] = sc.nextInt();
            }
        }
        pairSort(vs1, id1, n1);
        pairSort(vs2, id2, n2);
        int[] sum1 = new int[n1 + 1], sum2 = new int[n2 + 1];
        for (int i = n1 - 1; i >= 0; i--) sum1[i] = sum1[i + 1] + vs1[i];
        for (int i = n2 - 1; i >= 0; i--) sum2[i] = sum2[i + 1] + vs2[i];
        int max = 0, r = 0;
        for (int i = 0; i <= n2; i++) {
            int j = min(W - i * 2, n1);
            if (j >= 0) {
                int tmp = sum1[n1 - j] + sum2[n2 - i];
                if (max < tmp) {
                    max = tmp;
                    r = i;
                }
            }
        }
        System.out.println(max);
        int j = min(W - r * 2, n1);
        int[] res = new int[j + r];
        for (int i = 0; i < j; i++) res[i] = id1[n1 - i - 1];
        for (int i = 0; i < r; i++) res[j + i] = id2[n2 - i - 1];
        sort(res);
        for (int i = 0; i < res.length; i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(res[i]);
        }
        System.out.println();
    }
    
    void pairSort(int[] ks, int[] vs, int n) {
        long[] ls = new long[n];
        for (int i = 0; i < n; i++) {
            ls[i] = ((long)ks[i] << 32) | vs[i];
        }
        sort(ls);
        for (int i = 0; i < n; i++) {
            ks[i] = (int)(ls[i] >> 32);
            vs[i] = (int)ls[i];
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
            Locale.setDefault(Locale.US);
            try {
                System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
            } catch (Throwable e) {
            }
        }
        new Main().run();
        System.out.flush();
    }
}