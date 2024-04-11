import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class C {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        int a = sc.nextInt(), b = sc.nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++) t[i] = sc.nextInt() - 1;
        int[] num = new int[5];
        for (int i = 0; i < n; i++) num[t[i]]++;
        StringBuilder res = new StringBuilder();
        if (a == b) {
            for (int i = 0; i < a; i++) res.append("1 ");
            for (int i = 0; i < b; i++) res.append("2 ");
        } else if (a < b) {
            int m = 0, d = 4;
            while (m + num[d] < a) {
                m += num[d];
                d--;
            }
            for (int i = 0; i < n; i++) {
                if (t[i] > d || t[i] == d && m++ < a) res.append("1 ");
                else res.append("2 ");
            }
        } else if (a > b) {
            int m = 0, d = 0;
            while (m + num[d] < a) {
                m += num[d];
                d++;
            }
            for (int i = 0; i < n; i++) {
                if (t[i] < d || t[i] == d && m++ < a) res.append("1 ");
                else res.append("2 ");
            }
        }
        System.out.println(res.substring(0, res.length() - 1));
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
                throw new IOError(e);
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
        new C().run();
    }
}