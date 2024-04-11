import java.io.*;
import java.util.*;

public class Solution {


    private StringTokenizer st;
    private BufferedReader in;
    private PrintWriter out;

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] a = new int[2 * n];
        int[] posb = new int[1000000];
        Arrays.fill(posb, -1);
        for (int i = 0; i < n; ++i) {
            a[i] = a[n + i] = nextInt() - 1;
        }
        for (int i = 0; i < m; ++i) {
            posb[nextInt() - 1] = i;
        }
        int ans = 0;
        long[] q = new long[2 * n];
        for (int i = 0, j = 0; j < 2 * n; ++j) {
            q[j] = posb[a[j]];
            if (q[j] == -1) {
                i = j + 1;
                continue;
            }
            if (j > 0 && q[j] < q[j - 1]) {
                long cycles = (q[j - 1] - q[j] + m - 1) / m;
                q[j] += cycles * m;
            }
            while (i <= j && q[j] - q[i] >= m || j - i + 1 > n) {
                ++i;
            }
            ans = Math.max(ans, j - i + 1);
        }
        out.println(ans);
    }

    public void run() throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        eat("");
        
        solve();
        
        out.close();
    }
    
    void eat(String s) {
        st = new StringTokenizer(s);
    }
    
    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }
    
    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    
    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        new Solution().run();
    }
    
}