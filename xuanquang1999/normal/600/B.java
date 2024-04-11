import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt(), m = in.nextInt();
        Integer a[] = new Integer[n];
        int b[] = new int[m];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        for (int i = 0; i < m; ++i)
            b[i] = in.nextInt();

        Arrays.sort(a);
        for (int i = 0; i < m; ++i) {
            int lo = 0, hi = n - 1, res = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (a[mid] <= b[i]) {
                    res = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }
            out.printf("%d ", res + 1);
        }

        out.close();
    }
}