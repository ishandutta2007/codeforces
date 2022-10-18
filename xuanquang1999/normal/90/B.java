import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        String s[] = new String[n];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next();

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                boolean ok = true;
                for(int k = 0; k < m; ++k)
                    if (k != j && s[i].charAt(j) == s[i].charAt(k)) ok = false;
                for(int k = 0; k < n; ++k)
                    if (k != i && s[i].charAt(j) == s[k].charAt(j)) ok = false;
                if (ok) sb.append(s[i].charAt(j));
            }
        }

        System.out.println(sb.toString());
    }
}