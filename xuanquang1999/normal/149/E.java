import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int[] prefFunc(String s) {
        int pref[] = new int[s.length()];
        pref[0] = 0;
        int j = 0;
        for(int i = 1; i < s.length(); ++i) {
            while (j > 0 && s.charAt(i) != s.charAt(j))
                j = pref[j-1];
            if (s.charAt(i) == s.charAt(j))
                ++j;
            pref[i] = j;
        }
        return pref;
    }

    static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        String s = in.next();
        int q = in.nextInt(), ans = 0;
        for(int iq = 0; iq < q; ++iq) {
            String t = in.next();
            int pL[] = prefFunc(t+"#"+s);
            int pR[] = prefFunc(reverse(t)+"#"+reverse(s));

            int fL[] = new int[s.length()];
            for(int i = 0; i < s.length(); ++i) {
                fL[i] = pL[i+t.length()+1];
                if (i > 0)
                    fL[i] = Math.max(fL[i-1], fL[i]);
            }

            int fR[] = new int[s.length()];
            for(int i = s.length()-1; i >= 0; --i) {
                fR[i] = pR[s.length()-i+t.length()];
                if (i < s.length()-1)
                    fR[i] = Math.max(fR[i+1], fR[i]);
            }

//            for(int i = 0; i < s.length(); ++i)
//                out.printf("%d %d\n", fL[i], fR[i]);

            boolean found = (fL[s.length()-1] == t.length());
            for(int i = 0; i < s.length()-1; ++i)
                if (fL[i]+fR[i+1] >= t.length())
                    found = true;
            if (t.length() > 1 && found)
                ++ans;
        }
        out.println(ans);
        out.close();
    }
}