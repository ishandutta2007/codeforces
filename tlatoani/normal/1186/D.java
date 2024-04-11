import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class VusTheCossackAndNumbers {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = in.nextInt();
        int[] b = new int[n];
        boolean[] isInt = new boolean[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            double a = in.nextDouble();
            b[i] = (int) Math.floor(a);
            sum += b[i];
            isInt[i] = a == Math.floor(a);
        }
        for (int i = 0; i < n; i++) {
            if (sum < 0 && !isInt[i]) {
                sum++;
                b[i]++;
            }
            out.println(b[i]);
        }
        out.flush();
    }
}