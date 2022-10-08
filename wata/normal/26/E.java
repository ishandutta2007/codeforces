import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = false;//System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int N = sc.nextInt(), W = sc.nextInt();
        int[] ns = new int[N];
        for (int i = 0; i < N; i++) ns[i] = sc.nextInt();
        int sum = 0, min = ns[0], mini = 0;
        for (int i = 0; i < N; i++) {
            sum += ns[i];
            if (min > ns[i]) {
                min = ns[i];
                mini = i;
            }
        }
        if (W < min || sum < W) {
            if (W < 2 || sum < W || N == 1) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
                StringBuilder sb = new StringBuilder();
                sb.append(N).append(' ');
                for (int i = 0; i < ns[0] - (W - 1); i++) {
                    sb.append(1).append(' ');
                    sb.append(1).append(' ');
                }
                for (int i = 1; i < N - 1; i++) {
                    for (int j = 0; j < ns[i]; j++) {
                        sb.append(i + 1).append(' ');
                        sb.append(i + 1).append(' ');
                    }
                }
                sb.append(N).append(' ');
                sb.append(1).append(' ');
                for (int i = 0; i < ns[N - 1] * 2 - 2; i++) {
                    sb.append(N).append(' ');
                }
                for (int i = 0; i < (W - 1) * 2 - 1; i++) {
                    sb.append(1).append(' ');
                }
                System.out.println(sb.substring(0, sb.length() - 1));
            }
        } else {
            System.out.println("Yes");
            StringBuilder sb = new StringBuilder();
            if (W == min) sb.append(mini + 1).append(' ');
            for (int i = 0; i < N; i++) if (i != mini) {
                for (int j = 0; j < ns[i]; j++) {
                    sb.append(i + 1).append(' ');
                    sb.append(i + 1).append(' ');
                    if (--W == min) sb.append(mini + 1).append(' ');
                }
            }
            sb.append(mini + 1).append(' ');
            for (int i = 0; i < min - 1; i++) {
                sb.append(mini + 1).append(' ');
                sb.append(mini + 1).append(' ');
            }
            System.out.println(sb.substring(0, sb.length() - 1));
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
                System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
            } catch (Throwable e) {
            }
        }
        new Main().run();
        System.out.flush();
    }
}