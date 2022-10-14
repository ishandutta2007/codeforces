import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class IOtest {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());
            int a[] = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            Arrays.sort(a);
            int i = 1;
            int j = n - i;
            while (i <= n && i <= a[j]) {
                i++;
                j--;
            }
            out.println(i - 1);
        }
        out.flush();
    }

    private static int min(int a, int b) {
        return (a < b) ? a : b;
    }

    private static String isPassed(int n, int last_p) {
        if (n == 0)
            return "PASSED";
        if (n < 5 && n != 1)
            return "FAILED";
        int p = (int) (Math.log10((double) n) / Math.log10((double) 5));
        if (last_p == p)
            return "FAILED";
        if (p == 0)
            return "PASSED";
        return isPassed((n - (int) Math.pow(5, p)), p);
    }

    private static boolean isEvenBit(int i) {
        return (i & 1) == 0;
    }
}