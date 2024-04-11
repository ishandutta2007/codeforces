import java.io.PrintStream;
import java.util.Scanner;

public class PolygonForAngle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int angle = in.nextInt();
            int gcd = gcd(180, angle);
            if (angle + gcd != 180) {
                out.println(180 / gcd);
            } else {
                out.println(360 / gcd);
            }
        }
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}