import java.util.Scanner;

public class MagicGrid {
    static final int[][] MATRIX = {
            {8, 9, 1, 13},
            {3, 12, 7, 5},
            {0, 2, 4, 11},
            {6, 10, 15, 14}
    };

    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt() >> 2;
        StringBuilder builder = new StringBuilder();
        for (int y = 0; y < (n << 2); y++) {
            for (int x = 0; x < (n << 2); x++) {
                int k = ((y >> 2) * n) + (x >> 2);
                builder.append((k << 4) + MATRIX[y & 3][x & 3]);
                builder.append(x < (n << 2) - 1 ? ' ' : '\n');
            }
        }
        System.out.println(builder);
    }
}