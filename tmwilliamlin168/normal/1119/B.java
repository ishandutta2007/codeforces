import java.util.Arrays;
import java.util.Scanner;

public class B2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int h = sc.nextInt();

        int[] heights = new int[n];

        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            Arrays.sort(heights, 0, i + 1);

            int rem = h;

            for (int j = i; j >= 0; j -= 2) {
                if (rem < heights[j]) {
                    System.out.println(i);
                    return;
                }

                rem -= heights[j];
            }
        }

        System.out.println(n);
    }
}