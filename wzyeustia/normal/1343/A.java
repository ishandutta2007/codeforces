import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            int divide = 3;
            while (divide <= n) {
                if (n % divide == 0) {
                    System.out.println(n / divide);
                    break;
                }
                divide = divide * 2 + 1;
            }
        }
    }
}