import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String str = sc.next();
        int k = sc.nextInt();
        int[] forbid = new int[26];
        Arrays.fill(forbid, -1);
        for (int i = 0; i < k; ++i) {
            char[] f = sc.next().toCharArray();
            f[0] -= 'a';
            f[1] -= 'a';
            forbid[f[0]] = f[1];
            forbid[f[1]] = f[0];
        }
        int[] dp = new int[26];
        for (int i = 0; i < str.length(); ++i) {
            int v = str.charAt(i) - 'a';
            int next = dp[v];
            for (int j = 0; j < 26; ++j) {
                if (j != forbid[v]) {
                    next = Math.max(next, dp[j] + 1);
                }
            }
            dp[v] = next;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = Math.max(ans, dp[i]);
        }
        System.out.println(str.length() - ans);
    }

}