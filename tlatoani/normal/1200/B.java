import java.util.Scanner;

public class BlockAdventure {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = in.nextInt(); t > 0; t--) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int prev = in.nextInt();
            boolean answer = true;
            for (int i = 1; i < n; i++) {
                int next = in.nextInt();
                m += prev - Math.max(0, (next - k));
                prev = next;
                if (m < 0) {
                    answer = false;
                }
            }
            System.out.println(answer ? "YES" : "NO");
        }
    }
}