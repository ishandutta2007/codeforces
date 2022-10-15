import java.util.*;
 
public class C {
 
    static long MOD = 1000000007;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
 
        char[] line = scan.nextLine().toCharArray();
 
        dp = new long[line.length];
        Arrays.fill(dp, -1);
        for (int i = line.length - 1; i >= 0; i--) {
            count(line, i);
        }
 
        System.out.println(count(line, 0));
 
    }
 
    static long[] dp;
 
    static long count(char[] line, int idx) {
        if (idx == line.length) return 1;
        if (dp[idx] != -1) return dp[idx];
        char cur = line[idx];
 
        if (cur == 'w' || cur == 'm') return 0;
        long result = 0;
        if (cur == 'u' || cur == 'n') {
            if (idx < line.length - 1) {
                char next = line[idx + 1];
                if (next == cur) {
                    result += count(line, idx + 2);
                    result %= MOD;
                }
            }
        }
        result += count(line, idx + 1);
        result  %= MOD;
 
        dp[idx] = result;
        return result;
    }
 
}