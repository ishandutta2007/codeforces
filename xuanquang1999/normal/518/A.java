import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder(sc.next());
        String t = sc.next();

        for(int i = sb.length()-1; i >= 0; --i) {
            if (sb.charAt(i) < 'z') {
                sb.setCharAt(i, (char)(sb.charAt(i) + 1));
                break;
            } else sb.setCharAt(i, 'a');
        }

        String s = sb.toString();
        if (s.compareTo(t) >= 0)
            s = "No such string";
        System.out.println(s);
    }
}