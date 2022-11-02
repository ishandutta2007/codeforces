import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            long result = 0;
            int n = scanner.nextInt();
            int[] arr = new int[n];
            int[] count = new int[32];
            for (int j = 0; j < n; j++) {
                arr[j] = scanner.nextInt();
                int idx = 0;
                while (arr[j] > 0) {
                    idx++;
                    arr[j] /= 2;
                }
                count[idx]++;
            }

            for (int j = 0; j < 32; j++) {
                result += ((long) count[j]) * (count[j] - 1) / 2;
            }

            System.out.println(result);
        }
    }
}