import java.io.InputStreamReader;
import java.util.Scanner;

public class _1350B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] size = new int[n + 1];
            int[] crtLength = new int[n + 1];

            for (int j = 1; j <= n; j++)
                size[j] = scanner.nextInt();

            int max = 0;
            for (int j = 1; j <= n; j++) {
                crtLength[j]++;
                for (int m = 2; m * j <= n; m++) {
                    if (size[j] < size[m * j]) {
                        if (crtLength[j] > crtLength[m * j]) {
                            crtLength[m * j] = crtLength[j];
                        }
                    }
                }
                max = Math.max(max, crtLength[j]);
            }
            // System.out.println(Arrays.toString(crtLength));
            System.out.println(max);

        }
    }
}