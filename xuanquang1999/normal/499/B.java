import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        String s[] = new String[m];
        String t[] = new String[m];
        for (int i = 0; i < m; ++i) {
            s[i] = sc.next();
            t[i] = sc.next();
        }

        PrintWriter pw = new PrintWriter(System.out);
        for(int i = 0; i < n; ++i) {
            String w = sc.next();
            for(int j = 0; j < m; ++j) {
                if (w.equals(s[j])) {
                    if (s[j].length() > t[j].length())
                        w = t[j];
                    break;
                }
            }
            pw.printf("%s ", w);
        }
        pw.close();
    }
}