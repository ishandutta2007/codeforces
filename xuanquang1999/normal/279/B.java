import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), t = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int l = 0, cur = 0, ans = 0;
        for (int r = 0; r < n; ++r) {
            cur += a[r];
            while (cur > t) {
                cur -= a[l];
                ++l;
            }
            ans = Math.max(ans, r-l+1);
        }

        System.out.println(ans);
    }
}