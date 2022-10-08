import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class Main {
    static boolean LOCAL = System.getSecurityManager() == null;
    Scanner sc = new Scanner(System.in);
    
    int[] ps = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    
    void run() {
        int t = sc.nextInt();
        Map<String, int[]> points = new HashMap<String, int[]>();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            for (int j = 0; j < n; j++) {
                String name = sc.nextLine();
                if (!points.containsKey(name)) points.put(name, new int[100]);
                int[] qs = points.get(name);
                if (j < ps.length) qs[0] += ps[j];
                qs[1 + j]++;
            }
        }
        String win = null;
        for (Map.Entry<String, int[]> e : points.entrySet()) {
            if (win == null || comp1(points.get(win), e.getValue()) < 0) win = e.getKey();
        }
        System.out.println(win);
        win = null;
        for (Map.Entry<String, int[]> e : points.entrySet()) {
            if (win == null || comp2(points.get(win), e.getValue()) < 0) win = e.getKey();
        }
        System.out.println(win);
    }
    
    int comp1(int[] is, int[] js) {
        for (int i = 0; i < is.length; i++) if (is[i] != js[i]) return is[i] - js[i];
        return 0;
    }
    
    int comp2(int[] is, int[] js) {
        if (is[1] != js[1]) return is[1] - js[1];
        if (is[0] != js[0]) return is[0] - js[0];
        for (int i = 2; i < is.length; i++) if (is[i] != js[i]) return is[i] - js[i];
        return 0;
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