import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            cnt += x;
        }

        if (n == 1)
            System.out.println((cnt == 1) ? "YES" : "NO");
        else
            System.out.println((cnt == n-1) ? "YES" : "NO");
    }
}