import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            --a[i];
        }

        int cnt[] = new int[m];
        long ans = (long)n*(n-1)/2;
        for(int i = 0; i < n; ++i)
            ++cnt[a[i]];

        for(int i = 0; i < m; ++i)
            ans -= (long)cnt[i]*(cnt[i]-1)/2;

        System.out.println(ans);
    }
}