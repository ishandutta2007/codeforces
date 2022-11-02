import java.io.InputStreamReader;
import java.util.Scanner;

public class _1328C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();

            StringBuilder sbA = new StringBuilder();
            StringBuilder sbB = new StringBuilder();

            String strX = scanner.nextLine();
            strX = scanner.nextLine();

            int j = 0;
            boolean flag = true;
            while (j < n && flag) {
                char ch = strX.charAt(j++);
                switch (ch) {
                    case '0': {
                        sbA.append('0');
                        sbB.append('0');
                        break;
                    }
                    case '2': {
                        sbA.append('1');
                        sbB.append('1');
                        break;
                    }
                    case '1': {
                        sbA.append('1');
                        sbB.append('0');
                        flag = false;
                        break;
                    }
                }
            }

            while (j < n) {
                char ch = strX.charAt(j++);
                sbA.append('0');
                sbB.append(ch);
            }

            System.out.println(sbA.toString());
            System.out.println(sbB.toString());

        }
    }
}