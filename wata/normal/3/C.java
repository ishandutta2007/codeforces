import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[][] cs = new char[3][];
        for (int i = 0; i < 3; i++) cs[i] = sc.next().toCharArray();
        int num1 = 0, num2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cs[i][j] == 'X') {
                    num1++;
                } else if (cs[i][j] == '0') {
                    num2++;
                } else if (cs[i][j] != '.') {
                    System.out.println("illegal");
                    return;
                }
            }
        }
        if (num1 < num2 || num1 > num2 + 1) {
            System.out.println("illegal");
            return;
        }
        if (num1 > num2) {
            //0
            if (checkWin(cs, '0')) {
                System.out.println("illegal");
                return;
            }
            if (checkWin(cs, 'X')) {
                boolean ok = false;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) if (cs[i][j] == 'X') {
                        cs[i][j] = '.';
                        ok |= !checkWin(cs, 'X');
                        cs[i][j] = 'X';
                    }
                }
                if (ok) {
                    System.out.println("the first player won");
                    return;
                } else {
                    System.out.println("illegal");
                    return;
                }
            }
            if (num1 + num2 == 9) {
                System.out.println("draw");
                return;
            } else {
                System.out.println("second");
                return;
            }
        } else {
            //X
            if (checkWin(cs, 'X')) {
                System.out.println("illegal");
                return;
            }
            if (checkWin(cs, '0')) {
                boolean ok = false;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) if (cs[i][j] == '0') {
                        cs[i][j] = '.';
                        ok |= !checkWin(cs, '0');
                        cs[i][j] = '0';
                    }
                }
                if (ok) {
                    System.out.println("the second player won");
                    return;
                } else {
                    System.out.println("illegal");
                    return;
                }
            }
            System.out.println("first");
        }
    }
    
    boolean checkWin(char[][] cs, char c) {
        for (int i = 0; i < 3; i++) {
            boolean ok = true;
            for (int j = 0; j < 3; j++) {
                if (cs[i][j] != c) ok = false;
            }
            if (ok) return true;
        }
        for (int i = 0; i < 3; i++) {
            boolean ok = true;
            for (int j = 0; j < 3; j++) {
                if (cs[j][i] != c) ok = false;
            }
            if (ok) return true;
        }
        boolean ok = true;
        for (int j = 0; j < 3; j++) {
            if (cs[j][j] != c) ok = false;
        }
        if (ok) return true;
        ok = true;
        for (int j = 0; j < 3; j++) {
            if (cs[j][2 - j] != c) ok = false;
        }
        if (ok) return true;
        return false;
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