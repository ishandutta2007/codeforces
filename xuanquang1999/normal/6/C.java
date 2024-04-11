import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int l = 0, r = n-1;
        int sumA = 0, sumB = 0;
        while (l <= r) {
            if (sumA <= sumB) {
                sumA += a[l];
                ++l;
            } else {
                sumB += a[r];
                --r;
            }
        }

        System.out.printf("%d %d\n", l, n-r-1);

    }
}