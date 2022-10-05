import java.util.Scanner;

public class BowWowAndTheTimetable {

    public static void main(String[] args) {
        String s = new Scanner(System.in).nextLine();
        if (s.lastIndexOf('1') <= 0) {
            System.out.println(s.length() >> 1);
        } else {
            System.out.println((s.length() + 1 >> 1));
        }
    }
}