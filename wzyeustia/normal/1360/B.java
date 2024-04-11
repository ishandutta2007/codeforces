import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            int[] arr = new int[n];
            for (int j = 0; j < n; j++)
                arr[j] = scanner.nextInt();
            Arrays.sort(arr);

            int diff = Integer.MAX_VALUE;
            for (int j = 0; j < n - 1; j++) {
                if (diff > Math.abs(arr[j + 1] - arr[j]))
                    diff = Math.abs(arr[j + 1] - arr[j]);
            }

            System.out.println(diff);
        }
    }
}