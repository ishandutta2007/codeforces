import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] str = br.readLine().split(" ");
            int n = Integer.parseInt(str[0]);
            int k = Integer.parseInt(str[1]);

            if (n % 2 == 1 && k % 2 == 0) {
                System.out.println("NO");
            }

            if (n % 2 == k % 2) {
                if (n >= k) {
                    System.out.println("YES");
                    for (int j = 0; j < k - 1; j++)
                        System.out.print("1 ");
                    System.out.println(n - k + 1);
                } else
                    System.out.println("NO");
            }

            if (n % 2 == 0 && k % 2 == 1) {
                if (n >= k * 2) {
                    System.out.println("YES");
                    for (int j = 0; j < k - 1; j++)
                        System.out.print("2 ");
                    System.out.println(n - k * 2 + 2);
                } else
                    System.out.println("NO");
            }
        }
    }
}