import java.util.Scanner;

public class YouAreGivenTwoBinaryStrings {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = Integer.parseInt(in.nextLine()); t > 0; t--) {
            String x = in.nextLine();
            String y = in.nextLine();
            int i = y.lastIndexOf('1');
            System.out.println(x.length() - x.lastIndexOf('1', i + x.length() - y.length()) - (y.length() - i));
        }
    }
}