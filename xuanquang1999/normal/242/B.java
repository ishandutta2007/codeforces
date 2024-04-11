import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int l[] = new int[n];
        int r[] = new int[n];
        for (int i = 0; i < n; ++i) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }

        int maxLen = 0, ansId = 0;
        for (int i = 0; i < n; ++i) {
            int len = r[i] - l[i] + 1;
            if (len > maxLen) {
                maxLen = len;
                ansId = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!(l[ansId] <= l[i] && r[i] <= r[ansId])) {
                System.out.println(-1);
                return;
            }
        }

        System.out.println(ansId + 1);
    }
}