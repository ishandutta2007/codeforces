import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            int ans = 0;
            for (int j = 0; j < n; j++) {
                arr[j] = scanner.nextInt();
                if (arr[j] == 0)
                    ans++;
            }

            int j = 0;
            while (arr[j++] == 0) {
                ans--;
            }

            j = n - 1;
            while (arr[j--] == 0)
                ans--;

            System.out.println(ans);
        }
    }
}