import java.util.Scanner;

public class ZeroArray {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        //int[] array = new int[n];
        long sum = 0;
        long max = 0;
        for (int i = 0; i < n; i++) {
            //array[i] = in.nextInt();
            long k = in.nextLong();
            sum += k;
            max = Math.max(max, k);
        }
        if ((sum & 1) == 0 && sum >= (max << 1)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}