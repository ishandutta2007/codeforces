import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringJoiner;

public class YouAreGivenADecimalString {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        for (int x = 0; x < 10; x++) {
            StringJoiner joiner = new StringJoiner(" ");
            for (int y = 0; y < 10; y++) {
                int[] dp = new int[10];
                for (int i = 0; i < 10; i++) {
                    dp[i] = -1;
                }
                dp[x] = 0;
                dp[y] = 0;
                Queue<Integer> q = new LinkedList<>();
                q.add(x);
                q.add(y);
                while (!q.isEmpty()) {
                    int d = q.remove();
                    if (dp[(d + x) % 10] == -1 || dp[d] + 1 < dp[(d + x) % 10]) {
                        dp[(d + x) % 10] = dp[d] + 1;
                        q.add((d + x) % 10);
                    }
                    if (dp[(d + y) % 10] == -1 || dp[d] + 1 < dp[(d + y) % 10]) {
                        dp[(d + y) % 10] = dp[d] + 1;
                        q.add((d + y) % 10);
                    }
                }
                int answer = 0;
                for (int i = 1; i < s.length(); i++) {
                    if (dp[(10 + s.charAt(i) - s.charAt(i - 1)) % 10] == -1) {
                        answer = -1;
                        break;
                    } else {
                        answer += dp[(10 + s.charAt(i) - s.charAt(i - 1)) % 10];
                    }
                }
                joiner.add(answer + "");
            }
            System.out.println(joiner);
        }
    }
}