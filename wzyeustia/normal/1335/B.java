import java.io.InputStreamReader;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {

        String str = "abcdefghijklmnopqrstuvwxyz";
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            StringBuilder stringBuilder = new StringBuilder();
            for (int j = 0; j < n; j++)
                stringBuilder.append(str.charAt(j % b));

            System.out.println(stringBuilder.toString());

        }
    }
}