import java.util.Scanner;

public class Main {
    static int getBit(long n, int i) {
        return (int) ((n >> i) & 1);
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        long l = in.nextLong(), r = in.nextLong();

        int firstBit = -1;
        for (int i = 59; i >= 0; --i) {
            if (getBit(l, i) != getBit(r, i)) {
                firstBit = i;
                break;
            }
        }

        long ans = (1L << (firstBit + 1)) - 1;
        System.out.println(ans);
    }
}