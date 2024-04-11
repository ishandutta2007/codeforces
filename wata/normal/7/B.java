import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int t = sc.nextInt(), m = sc.nextInt();
        int[] id = new int[m];
        int ID = 1;
        boolean[] used = new boolean[1000];
        while (t-- > 0) {
            String op = sc.next();
            if (op.equals("alloc")) {
                int size = sc.nextInt();
                int p = -1;
                for (int i = 0; i < m; i++) if (id[i] == 0) {
                    int j = i;
                    while (j < m && id[j] == 0) {
                        j++;
                    }
                    if (j - i >= size) {
                        p = i;
                        for (int k = i; k < i + size; k++) id[k] = ID;
                        break;
                    }
                    i = j;
                }
                if (p >= 0) {
                    System.out.println(ID);
                    used[ID++] = true;
                } else {
                    System.out.println("NULL");
                }
            } else if (op.equals("erase")) {
                int n = sc.nextInt();
                if (0 <= n && n < used.length && used[n]) {
                    used[n] = false;
                    for (int i = 0; i < m; i++) if (id[i] == n) id[i] = 0;
                } else {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                }
            } else {
                int p = 0;
                for (int i = 0; i < m; i++) {
                    if (id[i] > 0) {
                        id[p++] = id[i];
                    }
                }
                while (p < m) id[p++] = 0;
            }
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