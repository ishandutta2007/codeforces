import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        ArrayList<String> list = new ArrayList<String>();
        int len = 0;
        for (;;) {
            String str = sc.nextLine();
            if (str == null) break;
            list.add(str);
            len = max(len, str.length());
        }
        for (int i = 0; i < len + 2; i++) {
            System.out.print('*');
        }
        System.out.println(); 
        int num = 0;
        for (String s : list) {
            StringBuilder sb = new StringBuilder();
            sb.append('*');
            if ((len - s.length()) % 2 == 0) {
                for (int i = 0; i < (len - s.length()) / 2; i++) {
                    sb.append(' ');
                }
                sb.append(s);
                for (int i = 0; i < (len - s.length()) / 2; i++) {
                    sb.append(' ');
                }
            } else {
                if (num++ % 2 == 0) {
                    for (int i = 0; i < (len - s.length()) / 2; i++) {
                        sb.append(' ');
                    }
                    sb.append(s);
                    for (int i = 0; i < (len - s.length() + 1) / 2; i++) {
                        sb.append(' ');
                    }
                } else {
                    for (int i = 0; i < (len - s.length() + 1) / 2; i++) {
                        sb.append(' ');
                    }
                    sb.append(s);
                    for (int i = 0; i < (len - s.length()) / 2; i++) {
                        sb.append(' ');
                    }
                }
            }
            sb.append('*');
            System.out.println(sb);
        }
        for (int i = 0; i < len + 2; i++) {
            System.out.print('*');
        }
        System.out.println();
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