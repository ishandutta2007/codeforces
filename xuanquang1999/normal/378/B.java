import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int a[][] = new int[2][n], ans[][] = new int[2][n];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 2; ++j) {
                a[j][i] = sc.nextInt();
                ans[j][i] = 0;
            }
        }

        int x = 0, y = 0;
        while (x < n && y < n) {
            if (a[0][x] < a[1][y]) {
                ans[0][x] = 1;
                ++x;
            } else {
                ans[1][y] = 1;
                ++y;
            }
            if (x+y == n) break;
        }
        while (x < n/2) {
            ans[0][x] = 1;
            ++x;
        }
        while (y < n/2) {
            ans[1][y] = 1;
            ++y;
        }

        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < n; ++j) System.out.print(ans[i][j]);
            System.out.println();
        }
    }

}