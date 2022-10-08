import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    void run() {
        int n = sc.nextInt();
        Map<String, Expr> macro = new HashMap<String, Expr>();
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            int p = 0;
            for (int j = 0; j < 7; p++) {
                if (str.charAt(p) != ' ') j++;
            }
            str = str.substring(p).trim();
            p = 0;
            while (str.charAt(p) != ' ') p++;
            String name = str.substring(0, p);
            str = str.substring(p).replaceAll(" ", "");
            Expr exp = new Parser(str.toCharArray(), macro).expr();
            macro.put(name, exp);
        }
        String str = sc.nextLine().replaceAll(" ", "");
        Expr expr = new Parser(str.toCharArray(), macro).expr();
        System.out.println(expr.ok ? "OK" : "Suspicious");
    }
    
    class Expr {
        boolean ok;
        char op;
        Expr(boolean ok, char op) {
            this.ok = ok;
            this.op = op;
        }
    }
    
    class Parser {
        char[] c;
        int p;
        Map<String, Expr> macro;
        Parser(char[] c, Map<String, Expr> macro) {
            this.c = c;
            this.macro = macro;
        }
        Expr expr() throws ParseException {
            Expr t = term();
            while (p < c.length && (c[p] == '+' || c[p] == '-')) {
                char op = c[p++];
                Expr u = term();
                t.ok &= u.ok;
                if (op == '-' && u.op == '+') {
                    t.ok = false;
                }
                t.op = '+';
            }
            return t;
        }
        Expr term() throws ParseException {
            Expr t = factor();
            while (p < c.length && (c[p] == '*' || c[p] == '/')) {
                char op = c[p++];
                Expr u = factor();
                t.ok &= u.ok;
                if (op == '/' && u.op != ' ') t.ok = false;
                if (t.op == '+' || u.op == '+') t.ok = false;
                t.op = '*';
            }
            return t;
        }
        Expr factor() throws ParseException {
            if (c[p] == '(') {
                p++;
                Expr t = expr();
                t.op = ' ';
                if (c[p] != ')') throw new ParseException();
                p++;
                return t;
            } else {
                String name = "";
                while (p < c.length && check(c[p])) {
                    name += c[p++];
                }
                if (macro.containsKey(name)) {
                    Expr e = macro.get(name);
                    return new Expr(e.ok, e.op);
                }
                return new Expr(true, ' ');
            }
        }
    }
    class ParseException extends RuntimeException {
    }
    
    boolean check(char c) {
        return "+-*/()".indexOf(c) < 0;
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