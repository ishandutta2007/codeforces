import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long[] vals = new long[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            vals[i] = Long.parseLong(st.nextToken());
        }
        long[][] inc = new long[n][n];
        while(k-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            inc[x-1][y-1] = c;
        }
        long[][] dp = new long[n][1<<n];
        long ret = 0;
        for(int i = 0; i < n; i++) {
        	Arrays.fill(dp[i], -1);
            dp[i][1<<i] = vals[i];
        }
        for(int mask = 1; mask < (1<<n); mask++) {
            for(int i = 0; i < n; i++) {
                if(dp[i][mask] < 0) continue;
                if(Integer.bitCount(mask) == m) {
                    ret = Math.max(ret, dp[i][mask]);
                    continue;
                }
                for(int j = 0; j < n; j++) {
                    if((mask&(1<<j))==0) {
                        dp[j][mask|(1<<j)] = Math.max(dp[j][mask|(1<<j)], dp[i][mask] + vals[j] + inc[i][j]);
                    }
                }
            }
        }
        System.out.println(ret);
    }
}