import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    static int getBit(long x, int i) {
        return (int) ((x >> i) & 1);
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int nTest = in.nextInt();
        for (int iTest = 0; iTest < nTest; ++iTest) {
            long l = in.nextLong(), r = in.nextLong();

            long ans;
            if (l == r)
                ans = l;
            else {
                int i;
                for (i = 59; i >= 0; --i)
                    if (getBit(l, i) != getBit(r, i))
                        break;

                //Get the number l with the last i+1 bit replaced by 0
                ans = (l >> i) << i;

                long a = ans + (1L << i) - 1, b = ans + (1L << (i + 1)) - 1;
                if (b <= r)
                    ans = b;
                else
                    ans = a;
            }

            out.println(ans);
        }

        out.close();
    }
}