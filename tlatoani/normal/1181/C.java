import java.util.Scanner;

public class Flag {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        char[][] blanket = new char[n][];
        for (int y = 0; y < n; y++) {
            blanket[y] = scanner.nextLine().toCharArray();
        }
        int[][] dpUp = new int[n][m];
        for (int x = 0; x < m; x++) {
            dpUp[0][x] = 1;
        }
        for (int y = 1; y < n; y++) {
            for (int x = 0; x < m; x++) {
                dpUp[y][x] = blanket[y][x] == blanket[y - 1][x] ? (dpUp[y - 1][x] + 1) : 1;
            }
        }
        int[][][] dpBin = new int[n][m][10];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (x > 0 && blanket[y][x] == blanket[y][x - 1]) {
                    for (int l = 0; (1 << l) <= dpUp[y][x]; l++) {
                        dpBin[y][x][l] = dpBin[y][x - 1][l] + 1;
                    }
                } else {
                    for (int l = 0; (1 << l) <= dpUp[y][x]; l++) {
                        dpBin[y][x][l] = 1;
                    }
                }
            }
        }
        long answer = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                int up = dpUp[y][x];
                //System.out.println("y = " + y + ", x = " + x + ", up = " + up);
                if (y + up >= n || y - (up << 1) < -1 || dpUp[y + up][x] != up || dpUp[y - up][x] < up) {
                    continue;
                }
                long extent = Long.MAX_VALUE;
                int upTemp = 0;
                for (int l = 0; (1 << l) <= up; l++) {
                    if ((up & (1 << l)) != 0) {
                        extent = Math.min(extent, dpBin[y - up - upTemp][x][l]);
                        extent = Math.min(extent, dpBin[y      - upTemp][x][l]);
                        extent = Math.min(extent, dpBin[y + up - upTemp][x][l]);
                        upTemp += 1 << l;
                        //System.out.println("after l = " + l + ", extent = " + extent);
                    }
                }
                //System.out.println("extent = " + extent);
                answer += extent;
            }
        }
        System.out.println(answer);
    }
}