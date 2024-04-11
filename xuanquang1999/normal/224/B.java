import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        int cnt[] = new int[100005];
        int cntDistinct = 0;

        int l = 0;
        int ansL = -1, ansR = -1;
        for(int r = 0; r < n; ++r) {
            if (cnt[a[r]] == 0) ++cntDistinct;
            ++cnt[a[r]];
            while (cntDistinct == k) {
                --cnt[a[l]];
                if (cnt[a[l]] == 0) --cntDistinct;
                ++l;
            }

            if (cntDistinct == k-1 && l > 0 && (ansL == -1 || r-l+1 < ansR-ansL)) {
                ansL = l;
                ansR = r+1;
            }
        }

        System.out.printf("%d %d", ansL, ansR);
    }

}