import java.util.Scanner;

public class TokitsukazeAndDiscardItems {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long m = in.nextLong();
        long k = in.nextLong();
        long removedPage = -1;
        long operations = 0;
        long offset = 0;
        for (long removed = 0; removed < m; removed++) {
            long special = in.nextLong() - 1 - offset;
            if (special / k == removedPage) {
                continue;
            }
            special += offset;
            special -= removed;
            offset = removed;
            operations++;
            removedPage = special / k;
        }
        System.out.println(operations);
    }
}