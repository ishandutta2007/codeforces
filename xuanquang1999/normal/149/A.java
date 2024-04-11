import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int a[] = new int[12];
        for(int i = 0; i < 12; ++i)
            a[i] = sc.nextInt();

        Arrays.sort(a);
        int i = 11;
        while (i >= 0 && k > 0) {
            k -= a[i];
            --i;
        }

        int ans = 11-i;
        if (k > 0) ans = -1;

        System.out.println(ans);
    }
}