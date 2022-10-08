import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    class Entry implements Comparable<Entry> {
        int key, val;
        Entry(int key, int val) {
            this.key = key;
            this.val = val;
        }
        public int compareTo(Entry o) {
            return o.key - key;
        }
    }
    
    int n;
    long A, B;
    int[] as, bs;
    
    void solve2() {
        boolean ok = false;
        for (int i = 0; i < 1 << (2 * n - 1); i++) if (Integer.bitCount(i) == n) {
            int a = 0, b = 0;
            for (int j = 0; j < 2 * n - 1; j++) if ((i >> j & 1) != 0) {
                a += as[j];
                b += bs[j];
            }
            if (a >= A && b >= B) ok = true;
        }
        if (!ok) throw new RuntimeException();
    }
    
    void solve() {
        Entry[] es = new Entry[2 * n - 1];
        Entry[] fs = new Entry[2 * n - 1];
        for (int i = 0; i < 2 * n - 1; i++) {
            es[i] = new Entry(as[i], i);
            fs[i] = new Entry(bs[i], i);
        }
        sort(es);
        sort(fs);
        long a = 0, b = 0;
        int[] used = new int[2 * n - 1];
        int ap = 0, bp = 2 * n - 2;
        for (int i = 0; i < n; i++) {
            while (used[es[ap].val] != 0) ap++;
            a += as[es[ap].val];
            b += bs[es[ap].val];
            used[es[ap].val] = 1;
            if (i < n - 1) {
                while (used[fs[bp].val] != 0) bp--;
                used[fs[bp].val] = -1;
            }
        }
        if (a < A || b < B) throw new RuntimeException();
        System.out.println("YES");
        boolean first = true;
        a = 0;
        b = 0;
        int m = 0;
        for (int i = 0; i < 2 * n - 1; i++) if (used[i] > 0) {
            if (!first) System.out.print(" ");
            first = false;
            System.out.print(i + 1);
            a += as[i];
            b += bs[i];
            m++;
        }
        if (a < A || b < B || m != n) throw new RuntimeException();
        System.out.println();
    }
    
    void _run() {
        for (;;) {
            Random rand = new Random();
            n = rand.nextInt(10) + 1;
            as = new int[2 * n - 1];
            bs = new int[2 * n - 1];
            A = 0;
            B = 0;
            for (int i = 0; i < 2 * n - 1; i++) {
                A += as[i] = rand.nextInt(100);
                B += bs[i] = rand.nextInt(100);
            }
            A = (A + 1) / 2;
            B = (B + 1) / 2;
            solve();
        }
    }
    
    void run() {
        int t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            as = new int[2 * n - 1];
            bs = new int[2 * n - 1];
            A = 0;
            B = 0;
            for (int i = 0; i < 2 * n - 1; i++) {
                A += as[i] = sc.nextInt();
                B += bs[i] = sc.nextInt();
            }
            A = (A + 1) / 2;
            B = (B + 1) / 2;
            solve();
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