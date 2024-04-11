import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        String s = in.nextLine().replace(" ", "");
        if (s.matches(".*(32|23).*"))
            System.out.println("Infinite");
        else {
            int r = 0;
            for (int i = 0; i < s.length() - 1; i++) {
                String a = s.substring(i, i + 2);
                if (a.equals("13") || a.equals("31")) r += 4;
                if (a.equals("12") || a.equals("21")) r += 3;
            }
            for (int i = 0; i < s.length() - 2; i++) {
                if (s.substring(i, i + 3).equals("312")) r--;
            }
            System.out.println("Finite\n" + r);
        }
    }
}