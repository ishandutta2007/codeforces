import java.util.Scanner;

public class HateA {

    public static void main(String[] args) {
        String t = new Scanner(System.in).nextLine();
        int lenS = t.length();
        for (char chara : t.toCharArray()) {
            if (chara == 'a') {
                lenS++;
            }
        }
        lenS /= 2;
        String s = t.substring(0, lenS);
        if (t.equals(s + s.replace("a", ""))) {
            System.out.println(s);
        } else {
            System.out.println(":(");
        }
    }
}