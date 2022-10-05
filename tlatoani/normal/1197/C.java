import java.util.Arrays;
import java.util.Scanner;

public class ArraySplitting {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        int k = in.nextInt();
        int min = in.nextInt();
        int prev = min;
        Integer[] diffs = new Integer[n - 1];
        for (int i = 0; i < n - 2; i++) {
            int curr = in.nextInt();
            diffs[i] = curr - prev;
            prev = curr;
        }
        int max = in.nextInt();
        diffs[n - 2] = max - prev;
        int answer = max - min;
        Arrays.sort(diffs);
        for (int i = n - 2; i >= n - k; i--) {
            answer -= diffs[i];
        }
        System.out.println(answer);
    }
}