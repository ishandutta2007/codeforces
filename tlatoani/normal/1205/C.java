import java.util.Scanner;

public class PalindromicPaths2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[][] grid = new int[n + 1][n + 1];
        grid[1][1] = 1;
        for (int y = 1; y <= n; y++) {
            for (int x = Math.max(4 - y, 1); x <= n; x++) {
                int qx, qy;
                if (y == 1) {
                    qx = x - 2;
                    qy = 1;
                } else if (y == 2) {
                    qx = x - 1;
                    qy = y - 1;
                } else {
                    qx = x;
                    qy = y - 2;
                }
                System.out.println("? " + qx + " " + qy + " " + x + " " + y);
                grid[x][y] = grid[qx][qy] ^ in.nextInt() ^ 1;
            }
            if (y == 2) {
                System.out.println("? 1 2 3 2");
                grid[1][2] = grid[3][2] ^ in.nextInt() ^ 1;
            }
        }
        int calibration = -1;
        for (int x = 1; x + 3 <= n; x++) {
            if ((grid[x][1] ^ grid[x + 2][1]) == (grid[x + 1][1] ^ grid[x + 3][1])) {
                System.out.println("? " + x + " 1 " + (x + 3) + " 1");
                calibration = in.nextInt() ^ grid[x + 1][1] ^ grid[x + 2][1] ^ 1;
                break;
            }
        }
        if (calibration == -1 && (grid[n - 2][1] ^ grid[n][1]) == (grid[n - 1][1] ^ grid[n][2])) {
            System.out.println("? " + (n - 2) + " 1 " + n + " 2");
            calibration = in.nextInt() ^ grid[n - 1][1] ^ grid[n][1] ^ 1;
        }
        if (calibration == -1 && (grid[n - 2][1] ^ grid[n - 1][2]) == (grid[n - 1][1] ^ grid[n][2])) {
            System.out.println("? " + (n - 2) + " 1 " + n + " 2");
            calibration = in.nextInt() ^ grid[n - 1][1] ^ grid[n - 1][2] ^ 1;
        }
        if (calibration == -1 && (grid[n - 2][1] ^ grid[n - 1][2]) == (grid[n - 2][2] ^ grid[n][2])) {
            System.out.println("? " + (n - 2) + " 1 " + n + " 2");
            calibration = in.nextInt() ^ grid[n - 2][2] ^ grid[n][1] ^ 1;
        }
        if (calibration == -1 && (grid[n - 1][1] ^ grid[n][2]) == (grid[n][1] ^ grid[n][3])) {
            System.out.println("? " + (n - 1) + " 1 " + n + " 3");
            calibration = in.nextInt() ^ grid[n][1] ^ grid[n][2] ^ 1;
        }
        if (calibration == -1 && (grid[n - 1][1] ^ grid[n][2]) == (grid[n - 1][2] ^ grid[n][3])) {
            System.out.println("? " + (n - 1) + " 1 " + n + " 3");
            calibration = in.nextInt() ^ grid[n - 1][2] ^ grid[n][2] ^ 1;
        }
        if (calibration == -1 && (grid[n - 1][1] ^ grid[n - 1][3]) == (grid[n - 1][2] ^ grid[n][3])) {
            System.out.println("? " + (n - 1) + " 1 " + n + " 3");
            calibration = in.nextInt() ^ grid[n - 1][2] ^ grid[n - 1][3] ^ 1;
        }
        if (calibration == -1) {
            for (int y = 1; y + 3 <= n; y++) {
                if ((grid[n][y] ^ grid[n][y + 2]) == (grid[n][y + 1] ^ grid[n][y + 3])) {
                    System.out.println("? " + n + " " + y + " " + n + " " + (y + 3));
                    calibration = in.nextInt() ^ grid[n][y + 1] ^ grid[n][y + 2] ^ 1;
                    break;
                }
            }
        }
        System.out.println("!");
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if ((x + y) % 2 == 0) {
                    System.out.print(grid[x][y]);
                } else {
                    System.out.print(grid[x][y] ^ calibration);
                }
            }
            System.out.println();
        }
    }
}