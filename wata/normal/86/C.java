import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
    Scanner sc = new Scanner(System.in);
    
    char[] DNA = "ACGT".toCharArray();
    
    int M = 1000000009;
    
    void run() {
        int n = sc.nextInt(), m = sc.nextInt();
        String[] s = new String[m];
        for (int i = 0; i < m; i++) s[i] = sc.next();
        sort(s);
        TreeSet<String> set = new TreeSet<String>();
        set.add("");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < s[i].length(); j++) set.add(s[i].substring(0, j + 1));
        }
        String[] pre = set.toArray(new String[0]);
        int N = pre.length;
        int[] finish = new int[N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < pre[i].length(); j++) {
                if (binarySearch(s, pre[i].substring(j)) >= 0) {
                    finish[i] = pre[i].length() - j;
                    break;
                }
            }
        }
        int[][] g = new int[N][4];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 4; j++) {
                String t = pre[i] + DNA[j];
                while (!set.contains(t)) t = t.substring(1);
                g[i][j] = binarySearch(pre, t);
            }
        }
        int[][][] dp = new int[n + 1][11][N];
        dp[0][0][binarySearch(pre, "")] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                for (int k = 0; k < N; k++) {
                    for (int x = 0; x < 4; x++) {
                        int k2 = g[k][x];
                        if (j + 1 <= pre[k2].length()) {
                            if (j + 1 <= finish[k2]) {
                                dp[i + 1][0][k2] += dp[i][j][k];
                                if (dp[i + 1][0][k2] >= M) dp[i + 1][0][k2] -= M;
                            } else {
                                dp[i + 1][j + 1][k2] += dp[i][j][k];
                                if (dp[i + 1][j + 1][k2] >= M) dp[i + 1][j + 1][k2] -= M;
                            }
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < N; i++) res = (res + dp[n][0][i]) % M;
        System.out.println(res);
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new C().run();
    }
}