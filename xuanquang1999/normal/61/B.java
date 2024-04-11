import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static String format(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); ++i)
            if (Character.isAlphabetic(s.charAt(i)))
                sb.append(Character.toLowerCase(s.charAt(i)));
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word[] = new String[3];
        for (int i = 0; i < 3; ++i)
            word[i] = format(sc.next());

        String possibleAns[] = new String[6];
        possibleAns[0] = word[0] + word[1] + word[2];
        possibleAns[1] = word[0] + word[2] + word[1];
        possibleAns[2] = word[1] + word[0] + word[2];
        possibleAns[3] = word[1] + word[2] + word[0];
        possibleAns[4] = word[2] + word[0] + word[1];
        possibleAns[5] = word[2] + word[1] + word[0];

        int q = sc.nextInt();
        for(int i = 0; i < q; ++i) {
            String ans = format(sc.next());
            boolean ok = false;
            for(int j = 0; j < 6; ++j)
                if (ans.equals(possibleAns[j])) ok = true;
            System.out.println((ok) ? "ACC" : "WA");
        }

    }
}