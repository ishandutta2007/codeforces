import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int ans = 0;
        char cur = 'a';
        for(int i = 0; i < s.length(); ++i) {
            int x = Math.abs(s.charAt(i) - cur);
            ans += Math.min(x, 26 - x);
            cur = s.charAt(i);
        }

        System.out.println(ans);
    }
}