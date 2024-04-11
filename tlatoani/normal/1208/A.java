import java.util.Scanner;

public class XORinacci {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[][] map = new int[2][2];
        map[0][1] = 0;
        map[1][1] = 1;
        map[1][0] = 2;
        for (int t = in.nextInt(); t > 0; t--) {
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int res = 0;
            for (int bit = 1; a > 0 || b > 0; bit <<= 1, a >>= 1, b >>= 1) {
                if (((a & 1) != 0 || (b & 1) != 0) && (n + map[a & 1][b & 1]) % 3 != 0) {
                    res += bit;
                }
            }
            System.out.println(res);
        }
    }
}