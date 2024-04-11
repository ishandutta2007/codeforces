import java.util.Scanner;

public class Main {
    public static int calc(int k, int x) {
        return x + ((x-1)/k)*5;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        String s[] = new String[n];
        for(int i = 0; i < n; ++i)
            s[i] = sc.next();
        String pass = sc.next();

        int cntLess = 0, cntEqual = 0;
        for(int i = 0; i < n; ++i) {
            if (s[i].length() < pass.length()) ++cntLess;
            if (s[i].length() == pass.length()) ++cntEqual;
        }

        System.out.printf("%d %d\n", calc(k, cntLess+1), calc(k, cntLess+cntEqual));

    }
}