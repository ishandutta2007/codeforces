import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), k = in.nextInt(), x = in.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();

        long pref[] = new long[n];
        long suff[] = new long[n];
        pref[0] = a[0];
        for (int i = 1; i < n; ++i)
            pref[i] = pref[i - 1] | a[i];
        suff[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suff[i] = suff[i + 1] | a[i];

        int powerX = 1;
        for(int i = 0; i < k; ++i)
            powerX *= x;

        long ans = 0;
        for(int i = 0; i < n; ++i) {
            long cur = (long)a[i]*powerX;
            if (i > 0)
                cur |= pref[i-1];
            if (i < n-1)
                cur |= suff[i+1];
            ans = Math.max(ans, cur);
        }

        System.out.println(ans);
    }
}