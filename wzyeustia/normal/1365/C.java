import java.io.InputStreamReader;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt() - 1;
            arr[k] += i;
        }
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt() - 1;
            arr[k] = ((arr[k] - i + n) % n);
        }

        int[] brr = new int[n];
        for (int i = 0; i < n; i++) {
            brr[arr[i]]++;
        }

        int max = -1;
        for (int i = 0; i < n; i++) {
            if (brr[i] > max) {
                max = brr[i];
            }
        }

        System.out.println(max);

    }
}