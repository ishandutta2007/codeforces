import java.util.Arrays;
import java.util.Scanner;

public class DIYWoodenLadder {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = in.nextInt(); t > 0; t--) {
            int n = in.nextInt();
            Integer[] planks = new Integer[n];
            for (int i = 0; i < n; i++) {
                planks[i] = in.nextInt();
            }
            Arrays.sort(planks);
            System.out.println(Math.min(n - 2, planks[n - 2] - 1));
        }
    }
}