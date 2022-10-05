import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.TreeSet;

public class InversionExpectation {
    static final long MOD = 998244353;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        long n = in.nextLong();
        long[] nums = new long[(int) n];
        long[] past = new long[(int) n + 1];
        long missing = 0;
        TreeSet<Long> treeSet = new TreeSet<>();
        SegmentTree segmentTree = new SegmentTree((int) n);
        long actualInversions = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextLong();
            if (nums[i] == -1L) {
                missing++;
            } else {
                past[(int) nums[i]] = missing;
                //actualInversions += treeSet.tailSet(nums[i]).size();
                actualInversions += (long) segmentTree.query((int) nums[i] + 1, (int) n);
                segmentTree.update((int) nums[i], 1);
                treeSet.add(nums[i]);
            }
        }
        if (missing == 0) {
            out.println(actualInversions % MOD);
            return;
        }
        // sums = sum of probs that the num is after a given -1
        long[] sumsBefore = new long[(int) n + 1];
        long[] sumsAfter = new long[(int) n + 1];
        for (long i = 1; i <= n; i++) {
            long addendBefore;
            long addendAfter;
            if (treeSet.contains(i)) {
                addendBefore = missing - past[(int) i];
                addendAfter = past[(int) i];
            } else {
                addendBefore = 0;
                addendAfter = 0;
            }
            sumsAfter[(int) i] = sumsAfter[(int) i - 1] + addendAfter;
            sumsBefore[(int) i] = sumsBefore[(int) i - 1] + addendBefore;
            //out.println("sums[" + i + "] = " + sumsAfter[(int) i]);
        }
        long expectedInOutInversions = 0;
        for (long i = 1; i <= n; i++) {
            if (treeSet.contains(i)) {
                continue;
            }
            expectedInOutInversions += sumsAfter[(int) i];
            expectedInOutInversions += sumsBefore[(int) n] - sumsBefore[(int) i];
        }
        long num = 0;
        //out.println("actual inversions = " + actualInversions);
        //out.println("expected in out inversions = " + expectedInOutInversions);
        //out.println("missing = " + missing + " => " + ((missing * n * (n - 1)) / 2));
        num += actualInversions * 2 * missing;
        num += expectedInOutInversions * 2;
        num += (missing * missing * (missing - 1)) / 2;
        num %= MOD;
        long denom = 2 * missing;
        //out.println("answer = " + num + " / " + denom);
        long denomInv = BigInteger.valueOf(denom).modInverse(BigInteger.valueOf(MOD)).longValue();
        long answer = num * denomInv;
        answer %= MOD;
        out.println(answer);
    }

    static class SegmentTree {
        final int n;
        final int[] array;

        SegmentTree(int n) {
            this.n = n;
            array = new int[n << 2];
        }

        int query(int from, int to) {
            return query(from, to, 1, n, 1);
        }

        int query(int from, int to, int segFrom, int segTo, int node) {
            int result = 0;
            if (from == segFrom && to == segTo) {
                result += array[node];
            } else {
                int midLower = (segFrom + segTo) / 2;
                int midUpper = midLower + 1;
                if (from <= midLower) {
                    result += query(from, Math.min(midLower, to), segFrom, midLower, node << 1);
                }
                if (to >= midUpper) {
                    result += query(Math.max(midUpper, from), to, midUpper, segTo, (node << 1) + 1);
                }
            }
            return result;
        }

        void update(int i, int dist) {
            update(i, dist, 1, n, 1);
        }

        int update(int i, int dist, int segFrom, int segTo, int node) {
            int change;
            if (segFrom == segTo) {
                change = dist - array[node];
            } else {
                int midLower = (segFrom + segTo) / 2;
                if (i <= midLower) {
                    change = update(i, dist, segFrom, midLower, node << 1);
                } else {
                    change = update(i, dist, midLower + 1, segTo, (node << 1) + 1);
                }
            }
            array[node] += change;
            return change;
        }
    }
}