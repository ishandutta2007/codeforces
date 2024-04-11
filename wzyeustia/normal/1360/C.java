import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            int[] arr = new int[n];
            for (int j = 0; j < n; j++)
                arr[j] = scanner.nextInt();
            Arrays.sort(arr);

            boolean flag = false;
            int odd = 0;
            int even = 0;
            for (int j = 0; j < n; j++) {
                if (j + 1 < n) {
                    if (Math.abs(arr[j + 1] - arr[j]) == 1) {
                        flag = true;
                    }
                }
                if (arr[j] % 2 == 1)
                    odd++;
                else
                    even++;
            }

            if (odd % 2 == 0) {
                System.out.println("YES");
            } else if (flag) {
                System.out.println("YES");
            } else
                System.out.println("NO");

        }
    }
}