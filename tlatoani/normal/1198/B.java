import java.util.Scanner;
import java.util.StringJoiner;
import java.util.TreeMap;

public class WelfareState {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] balances = new int[n + 1];
        int[] lastUpdate = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            balances[i] = in.nextInt();
        }
        int q = in.nextInt();
        TreeMap<Integer, Integer> payouts = new TreeMap<>();
        for (int t = 1; t <= q; t++) {
            if (in.nextInt() == 1) {
                int p = in.nextInt();
                balances[p] = in.nextInt();
                lastUpdate[p] = t;
            } else {
                int x = in.nextInt();
                while (!payouts.isEmpty() && payouts.lastEntry().getValue() <= x) {
                    payouts.remove(payouts.lastKey());
                }
                payouts.put(t, x);
            }
        }
        payouts.put(q + 1, 0);
        StringJoiner joiner = new StringJoiner(" ");
        for (int i = 1; i <= n; i++) {
            joiner.add(Math.max(balances[i], payouts.higherEntry(lastUpdate[i]).getValue()) + "");
        }
        System.out.println(joiner);
    }
}