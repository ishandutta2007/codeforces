import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    static int ans;

    static String combine(String s, String t) {
        String w = t + "#" + s;

        int pref[] = new int[w.length()];
        pref[0] = 0;
        int j = 0;
        for (int i = 1; i < w.length(); ++i) {
            while (j > 0 && w.charAt(i) != w.charAt(j))
                j = pref[j - 1];
            if (w.charAt(i) == w.charAt(j))
                ++j;
            pref[i] = j;
        }

        for (int i = t.length() + 1; i < w.length(); ++i)
            if (pref[i] == t.length())
                return s;

        int x = pref[w.length() - 1];
        StringBuilder ans = new StringBuilder(s);
        for(int i = x; i < t.length(); ++i)
            ans.append(t.charAt(i));
        return ans.toString();
    }

    static void Solve(String s1, String s2, String s3) {
        String res = s1;
        res = combine(res, s2);
        res = combine(res, s3);
        ans = Math.min(ans, res.length());
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        String s1 = in.next();
        String s2 = in.next();
        String s3 = in.next();

        ans = Integer.MAX_VALUE;
        Solve(s1, s2, s3);
        Solve(s1, s3, s2);
        Solve(s2, s1, s3);
        Solve(s2, s3, s1);
        Solve(s3, s1, s2);
        Solve(s3, s2, s1);

        out.println(ans);
        out.close();
    }
}