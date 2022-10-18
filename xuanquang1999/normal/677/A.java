import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), h = sc.nextInt();

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int x = sc.nextInt();
            ans += (x > h) ? 2 : 1;
        }

        System.out.println(ans);
    }
}