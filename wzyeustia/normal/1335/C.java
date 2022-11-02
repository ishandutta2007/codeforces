import java.io.InputStreamReader;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int[] count = new int[n + 1];
            for (int j = 0; j < n; j++) {
                count[scanner.nextInt()]++;
            }

            if (n == 1) {
                System.out.println("0");
                continue;
            }

            int numOfKinds = 0;
            int max = 0;
            for (int j = 0; j <= n; j++) {
                if (count[j] != 0) {
                    numOfKinds++;
                    if (max < count[j])
                        max = count[j];
                }
            }

            int ans;
            if (numOfKinds < max)
                ans = numOfKinds;
            else if (numOfKinds == max)
                ans = max - 1;
            else ans = max;

            System.out.println(ans);
        }
    }
}