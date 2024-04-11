import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        String s = in.nextToken(), p = in.nextToken();

        int[] pref = pref(p);
        
        int maxOcc = s.length()/  p.length();
        
        
        int[][][] dp = new int[s.length() + 1][maxOcc + 1][p.length()];
        
        int INF = Integer.MAX_VALUE/ 3;
        for (int[][] i : dp) {
            for (int[] j : i) {
                Arrays.fill(j, INF);
            }
        }
        dp[0][0][0] = 0;
        
        int[][] next = new int[26][p.length()];
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < p.length(); j++) {
                int k = j;
                char c = (char) (i + 'a');
                while (k > 0 && p.charAt(k) != c) {
                    k = pref[k - 1];
                }
                if (p.charAt(k) == c) {
                    k++;
                }
                next[i][j] = k;
            }
        }
        for (int pos = 0; pos < s.length(); pos++) {
            for (int curOcc = 0; curOcc <= maxOcc; curOcc++) {
                for (int match = 0; match < p.length(); match++) {
                    int val = dp[pos][curOcc][match];
                    if (val == INF) {
                        continue;
                    }
                    
                    // skip
                    dp[pos + 1][curOcc][match]= Math.min(dp[pos + 1][curOcc][match], val + 1);
                    
                    // take
                    int newMatch = next[s.charAt(pos) - 'a'][match];
                    if (newMatch == p.length()) {
                        dp[pos + 1][curOcc + 1][0] = Math.min(dp[pos + 1][curOcc + 1][0], val);
                    } else {
                        dp[pos + 1][curOcc][newMatch] = Math.min(dp[pos + 1][curOcc][newMatch], val);
                    }
                }
            }
        }
        
        int[] ans = new int[s.length() + 1];
        
        for (int occs = 0; occs <= maxOcc; occs++) {
            for (int match = 0; match < p.length(); match++) {
                if (dp[s.length()][occs][match] != INF) {
                    ans[dp[s.length()][occs][match]] = Math.max(ans[dp[s.length()][occs][match]], occs);
                }
            }
        }
        int[] ansReal = new int[s.length() + 1];
        
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                ansReal[i] = Math.max(ansReal[i], Math.min(ans[j], (s.length() - i) / p.length()));
            }
        }
        
        for (int i = 0; i <= s.length(); i++) {
            out.print(ansReal[i] + " ");
        }
        
    }

    private int[] pref(String s) {
        int n = s.length();
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            int k = p[i - 1];
            while (k > 0 && s.charAt(k) != s.charAt(i)) {
                k = p[k - 1];
            }
            if (s.charAt(k) == s.charAt(i)) {
                k++;
            }
            p[i] = k;
        }
        return p;
    }

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
        new C().run();
    }
}