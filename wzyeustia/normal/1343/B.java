import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            if (n % 4 != 0) {
                System.out.println("NO");
                continue;
            }

            StringBuilder stringBuilder = new StringBuilder();
            for (int j = 2; j <= n; j += 2) {
                stringBuilder.append(j);
                stringBuilder.append(" ");
            }

            for (int j = 1; j < n - 1; j += 2) {
                stringBuilder.append(j);
                stringBuilder.append(" ");
            }

            stringBuilder.append(n - 1 + n / 2);

            System.out.println("YES");
            System.out.println(stringBuilder.toString());

        }
    }
}