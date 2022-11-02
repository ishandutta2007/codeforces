import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            int max = 0;
            int ans = -2;
            for (int j = 0; j < n; j++) {
                arr[j] = scanner.nextInt();
                max = Math.max(max, arr[j]);
            }

            for (int j = 0; j < n; j++) {
                if (arr[j] == max) {
                    if (j > 0 && arr[j] > arr[j - 1]) {
                        ans = j;
                        break;
                    }
                    if (j < n - 1 && arr[j] > arr[j + 1]) {
                        ans = j;
                        break;
                    }
                }
            }

            System.out.println(ans + 1);
        }
    }
}