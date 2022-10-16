import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D2 {

    FastScanner in;
    PrintWriter out;

    char[] c;
    int n;

    final int mod = 1_000_000_007;

    String solve(String s) {
        c = s.toCharArray();
        n = c.length;

        final int INF = -1;
        int[] count = new int[n + 1];
        int[] min = new int[n + 1];
        Arrays.fill(count, 0);
        Arrays.fill(min, INF);

        min[0] = 0;
        count[0] = 1;

        int[] array = new int[n];
        int tmp = 0;
        for (int ch = 0; ch < 2; ch++) {
            for (int j = 0; j < n; j++) {
                if (c[j] == ch + '0') {
                    array[tmp++] = j;
                }
            }
        }

        BigInteger ans = null;
        int[] newArray = new int[n];
        for (int len = 1; len <= n; len++) {
            int size = n - len + 1;
            for (int i = 0; i < size; i++) {
                int k = array[i];
                if (c[k] == '0') {
                    continue;
                }
                if (k + len < n && c[k + len] != '1') {
                    continue;
                }
                if (min[k] == -1) {
                    continue;
                }

                count[k + len] += count[k];
                if (count[k + len] >= mod) {
                    count[k + len] -= mod;
                }

                
                if (min[k + len] == -1 || min[k + len] > min[k] + 1) {
                    min[k + len] = min[k] + 1;
                }

                if (k + len == n) {
                    BigInteger relax = new BigInteger(s.substring(k), 2)
                            .add(BigInteger.valueOf(min[n]));
                    if (ans != null) {
                        ans = ans.min(relax);
                    } else {
                        ans = relax;
                    }
                }
            }
            tmp = 0;
            for (int ch = 0; ch < 2; ch++) {
                for (int i = 0; i < size; i++) {
                    int k = array[i];
                    if (k == 0) {
                        continue;
                    }
                    if (c[k - 1] == '0' + ch) {
                        newArray[tmp++] = k - 1;
                    }
                }
            }
            for (int i = 0; i < tmp; i++) {
                array[i] = newArray[i];
            }
        }
        return count[n] + "\n" + ans.mod(BigInteger.valueOf(mod));
        
    }
    

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        
        out.println(solve(in.nextToken()));
        
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new D2().run();
    }
}