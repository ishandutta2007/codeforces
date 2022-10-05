import java.util.Arrays;
import java.util.Scanner;

public class MaximumMedian {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long k = in.nextInt();
        Long[] array = new Long[n];
        for (int i = 0; i < n; i++) {
            array[i] = in.nextLong();
        }
        Arrays.sort(array);
        int i;
        long li;
        for (i = n >> 1, li = 1; i < n - 1 && k >= (array[i + 1] - array[i]) * li; i++, li++) {
            k -= (array[i + 1] - array[i]) * li;
        }
        long answer = array[i];
        answer += k / li;
        System.out.println(answer);
    }
}