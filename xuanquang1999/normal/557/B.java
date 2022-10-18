import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), w = sc.nextInt();
        int a[] = new int[2*n];
        for(int i = 0; i < 2*n; ++i)
            a[i] = sc.nextInt();

        Arrays.sort(a);

        long ans = Math.min(3L*Math.min(a[0]*2, a[n])*n, 2*w);
        System.out.printf("%.15g\n", ans/2.0);
    }
}