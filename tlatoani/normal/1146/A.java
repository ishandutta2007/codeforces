import java.util.Scanner;

public class LoveA {

    public static void main(String[] args) {
        String s = new Scanner(System.in).nextLine();
        int amt = 0;
        for (char chara : s.toCharArray()) {
            if (chara == 'a') {
                amt++;
            }
        }
        System.out.println(Math.min(s.length(), (2 * amt) - 1));
    }
}