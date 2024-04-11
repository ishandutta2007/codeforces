import java.io.PrintStream;
import java.util.*;

public class Parenthesis {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int n = Integer.parseInt(in.nextLine());
        int evenAmt = 0;
        Map<Integer, Integer> firstAmt = new HashMap<>();
        Map<Integer, Integer> secondAmt = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String sequence = in.nextLine();
            int curr = 0;
            int min = 0;
            for (char chara : sequence.toCharArray()) {
                if (chara == '(') {
                    curr++;
                } else {
                    curr--;
                }
                min = Math.min(min, curr);
            }
            int end = curr;
            if (end == 0 && min >= 0) {
                evenAmt++;
            } else if (end > 0 && min >= 0) {
                firstAmt.merge(end, 1, (a, b) -> a + b);
            } else if (end < 0 && min >= end) {
                secondAmt.merge(-end, 1, (a, b) -> a + b);
            }
        }
        int totalPairs = evenAmt / 2;
        for (int key : firstAmt.keySet()) {
            int leftAmt = firstAmt.get(key);
            Integer rightAmt = secondAmt.get(key);
            if (rightAmt != null) {
                totalPairs += Math.min(leftAmt, rightAmt);
            }
        }
        out.println(totalPairs);
    }
}