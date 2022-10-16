import java.io.*;
import java.util.*;

public class A {

    List<Integer>[] graph;
    
    void solve() {
        int n = in.nextInt();
        String[] s = new String[n];
        boolean[][] a = new boolean[26][26];
        for (int i = 0; i < n; i++) {
            s[i] = in.next();
        }
        
        for (int i = 0; i < n - 1; i++) {
            
            int len = 0;
            while (len < s[i].length() && len < s[i + 1].length() && s[i].charAt(len) == s[i + 1].charAt(len)) {
                len++;
            }
            
            if (len == s[i].length()) {
                continue;
            }
            if (len == s[i + 1].length()) {
                out.println("Impossible");
                return;
            }
            
            a[s[i].charAt(len) - 'a'][s[i + 1].charAt(len) - 'a'] = true;
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    a[i][j] |= a[i][k] & a[k][j];
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                if (a[i][j] && a[j][i]) {
                    out.println("Impossible");
                    return;
                }
            }
        }
        
        boolean[] used = new boolean[26];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            int t = -1;
            for (int j = 0; j < 26; j++) {
                if (!used[j]) {
                    boolean ok = true;
                    for (int k = 0; k < 26; k++) {
                        if (!used[k] && a[k][j]) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        t = j;
                        break;
                    }
                }
            }
            if (t == -1) {
                throw new AssertionError();
            }
            ans.add(t);
            used[t] = true;
        }
        for (int i : ans) {
            out.print((char) (i + 'a'));
        }
        out.println();
    }

    FastScanner in;
    PrintWriter out;

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
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

    public static void main(String[] args) {
        new A().run();

    }
}