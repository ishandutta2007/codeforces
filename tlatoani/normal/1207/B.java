import java.util.*;

public class SquareFilling {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] matrix = new int[n + 2][m + 2];
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= m; x++) {
                matrix[y][x] = in.nextInt();
            }
        }
        Set<Integer> operations = new HashSet<>();
        boolean possible = true;
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= m; x++) {
                if (matrix[y][x] == 1) {
                    boolean pos = false;
                    for (int dy = -1; dy < 2; dy += 2) {
                        for (int dx = -1; dx < 2; dx += 2) {
                            if (matrix[y + dy][x] * matrix[y + dy][x + dx] * matrix[y][x + dx] != 0) {
                                pos = true;
                                operations.add((Math.min(y, y + dy) << 8) + Math.min(x, x + dx));
                                break;
                            }
                        }
                    }
                    if (!pos) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible ) {
            System.out.println(operations.size());
            for (int operation : operations) {
                System.out.println((operation >> 8) + " " + (operation & 255));
            }
        } else {
            System.out.println(-1);
        }
    }
}