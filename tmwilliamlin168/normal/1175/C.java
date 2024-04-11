import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    static Scanner sc;
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i<T; i++) {
            out.println(query());
        }
        out.close();
    }

    static int query() {
        int n = sc.nextInt();
        int k = sc.nextInt();
//        if (k == 0) {
//            int result = sc.nextInt();
//            sc.nextLine();
//            return result;
//        }
        int[] x = new int[n];
        int lx = 0, rx = 0;
        boolean started = false;
        int newV, current;
        for (int ni = 0; ni < n; ni++) {
            x[ni] = sc.nextInt();
            if (ni >= k) {
                if (!started) {
                    lx = x[ni - k];
                    rx = x[ni];
                    started = true;
                } else {
                    current = (rx - lx);
                    newV = x[ni] - x[ni - k];
                    if (current > newV) {
                        lx = x[ni - k];
                        rx = x[ni];
                    }
                }
            }
        }
        return ((rx - lx) /2) + lx;
    }

}