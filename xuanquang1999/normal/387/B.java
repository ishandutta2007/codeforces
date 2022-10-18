import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int a[] = new int[n];
        int b[] = new int[m];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        for(int i = 0; i < m; ++i)
            b[i] = sc.nextInt();

        int j = m-1, ans = 0;
        for(int i = n-1; i >= 0; --i) {
            if (j >= 0 && b[j] >= a[i])
                --j;
            else
                ++ans;
        }

        System.out.println(ans);
    }
}