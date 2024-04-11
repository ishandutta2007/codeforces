import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), x = sc.nextInt();

        Integer[] a = new Integer[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        Arrays.sort(a);

        long ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (long)a[i]*x;
            x = Math.max(1, x-1);
        }

        System.out.println(ans);
    }
}