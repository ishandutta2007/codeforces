//package april_19;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Daniel
 * @since 2019/4/11 17:55
 */
public class GlobalRound2_E {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
//        Scanner scanner = new Scanner(GlobalRound2_E.class.getResourceAsStream("/Grobalround2_E"));
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        long totalCount = solve(n, nums);
        System.out.printf("%d", totalCount);
    }

    static long solve(int n, int[] nums) {
        long total_count = 0;
        int j = 0;
        int first_not_0 = 0;
        while (j < n) {
            while (first_not_0 < j && nums[j] >= 2 * nums[first_not_0]) {
                total_count += nums[first_not_0];
                nums[j] -= 2 * nums[first_not_0];
                nums[first_not_0] = 0;
                first_not_0++;
            }
            if (first_not_0 == j) {
                total_count += nums[j] / 3;
                nums[j] = nums[j] % 3;
            } else {
                total_count += nums[j] / 2;
                nums[first_not_0] -= nums[j] / 2;
                nums[j] = nums[j] % 2;
            }
            j++;
        }
        return total_count;
    }
}