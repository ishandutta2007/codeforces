import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();

        int cnt[] = new int[256];
        for (int i = 0; i < n; ++i)
            ++cnt[Character.toLowerCase(s.charAt(i))];

        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] == 0) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }
}