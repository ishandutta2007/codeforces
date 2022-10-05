import java.io.PrintStream;
import java.util.Scanner;

public class Postcard {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintStream out = System.out;
        solve(in, out);
    }

    static void solve(Scanner in, PrintStream out) {
        String encoded = in.nextLine();
        int k = in.nextInt();
        int canes = 0;
        int snowflakes = 0;
        for (char chara : encoded.toCharArray()) {
            if (chara == '?') {
                canes++;
            } else if (chara == '*') {
                snowflakes++;
            }
        }
        int rawLength = encoded.length() - canes - snowflakes;
        int minLength = rawLength - canes - snowflakes;
        int maxLength;
        if (snowflakes > 0) {
            maxLength = Integer.MAX_VALUE;
        } else {
            maxLength = rawLength;
        }
        if (k < minLength || k > maxLength) {
            out.println("Impossible");
        } else if (snowflakes > 0) {
            int toAdd = k - minLength;
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < encoded.length(); i++) {
                if (encoded.charAt(i) == '?') {
                    continue;
                } else if (encoded.charAt(i) == '*') {
                    for (; toAdd > 0; toAdd--) {
                        builder.append(encoded.charAt(i - 1));
                    }
                } else if (i == encoded.length() - 1 || (encoded.charAt(i + 1) != '?' && encoded.charAt(i + 1) != '*')) {
                    builder.append(encoded.charAt(i));
                }
            }
            out.println(builder.toString());
        } else {
            StringBuilder builder = new StringBuilder();
            int toAdd = k - minLength;
            for (int i = 0; i < encoded.length(); i++) {
                if (encoded.charAt(i) == '?') {
                    if (toAdd > 0) {
                        builder.append(encoded.charAt(i - 1));
                        toAdd--;
                    }
                } else if (i == encoded.length() - 1 || encoded.charAt(i + 1) != '?') {
                    builder.append(encoded.charAt(i));
                }
            }
            out.println(builder.toString());
        }
    }
}