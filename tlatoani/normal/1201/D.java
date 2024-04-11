import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class TreasureHunting {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextInt(); // m doesn't matter lol
        int k = in.nextInt();
        int q = in.nextInt();
        long[] maxTreasure = new long[n + 1];
        long[] minTreasure = new long[n + 1];
        n = 0;
        for (int i = 0; i < k; i++) {
            int y = in.nextInt();
            long x = in.nextLong();
            n = Math.max(n, y);
            maxTreasure[y] = Math.max(maxTreasure[y], x);
            minTreasure[y] = minTreasure[y] == 0 ? x : Math.min(minTreasure[y], x);
        }
        TreeSet<Long> safeColumns = new TreeSet<>();
        for (int i = 0; i < q; i++) {
            safeColumns.add(in.nextLong());
        }
        Long[] dpPrev = new Long[]{-1L, null, null, null};
        Long[] xsPrev = new Long[]{1L, null, null, null};
        for (int i = 1; i <= n; i++) {
            if (minTreasure[i] == 0) {
                if (i == 1) {
                    xsPrev = new Long[]{safeColumns.first(), null, null, null};
                    dpPrev = new Long[]{xsPrev[0] - 1L, null, null, null};
                } else {
                    for (int h = 0; h < 4; h++) {
                        if (xsPrev[h] != null) {
                            dpPrev[h]++;
                        }
                    }
                }
                continue;
            }
            Long[] dp = new Long[4];
            Long[] xs;
            if (i < n) {
                xs = new Long[]{
                        safeColumns.floor(minTreasure[i]),
                        safeColumns.ceiling(minTreasure[i]),
                        safeColumns.floor(maxTreasure[i]),
                        safeColumns.ceiling(maxTreasure[i])
                };
            } else {
                xs = new Long[]{minTreasure[i], maxTreasure[i], null, null};
            }
            //System.out.println("i = " + i + ", minTreasure = " + minTreasure[i] + ", maxTreasure = " + maxTreasure[i]);
            //System.out.println("xs = " + Arrays.toString(xs));
            for (int j = 0; j < 4; j++) {
                if (xs[j] == null) {
                    continue;
                }
                dp[j] = Long.MAX_VALUE;
                for (int h = 0; h < 4; h++) {
                    if (xsPrev[h] == null) {
                        continue;
                    }
                    long addend = 1;
                    if (xsPrev[h] < xs[j]) {
                        addend += Math.abs(xsPrev[h] - minTreasure[i]);
                        addend += maxTreasure[i] - minTreasure[i];
                        addend += Math.abs(xs[j] - maxTreasure[i]);
                    } else {
                        addend += Math.abs(xsPrev[h] - maxTreasure[i]);
                        addend += maxTreasure[i] - minTreasure[i];
                        addend += Math.abs(xs[j] - minTreasure[i]);
                    }
                    dp[j] = Math.min(dp[j], dpPrev[h] + addend);
                }
            }
            //System.out.println("dp = " + Arrays.toString(dp));
            dpPrev = dp;
            xsPrev = xs;
        }
        long answer = Long.MAX_VALUE;
        for (int h = 0; h < 4; h++) {
            if (xsPrev[h] != null) {
                answer = Math.min(answer, dpPrev[h]);
            }
        }
        System.out.println(answer);
    }
}