import java.util.Arrays;
import java.util.Scanner;

public class TokitsukazeCSLAndStoneGame {
    static final String PLAYER_1_WIN = "sjfnb";
    static final String PLAYER_2_WIN = "cslnb";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Long[] piles = new Long[n];
        for (int i = 0; i < n; i++) {
            piles[i] = in.nextLong();
        }
        Arrays.sort(piles);
        if (n > 1 && piles[1] == 0L) {
            System.out.println(PLAYER_2_WIN);
            return;
        }
        boolean foundSamePair = false;
        for (int i = 1; i < n; i++) {
            if (piles[i - 1].equals(piles[i])) {
                if (foundSamePair) {
                    System.out.println(PLAYER_2_WIN);
                    return;
                } else {
                    foundSamePair = true;
                }
                if (i >= 2 && piles[i - 2].equals(piles[i - 1] - 1)) {
                    System.out.println(PLAYER_2_WIN);
                    return;
                }
            }
        }
        long turnAmount = 0;
        for (long i = 0; i < n; i++) {
            turnAmount += piles[(int) i] - i;
        }
        if (turnAmount % 2 == 1) {
            System.out.println(PLAYER_1_WIN);
        } else {
            System.out.println(PLAYER_2_WIN);
        }
    }
}