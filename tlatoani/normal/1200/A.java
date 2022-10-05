import java.util.Scanner;
import java.util.TreeSet;

public class Hotelier {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        TreeSet<Integer> disp = new TreeSet<>();
        for (int i = 0; i < 10; disp.add(i++));
        in.nextLine();
        for (char chara : in.nextLine().toCharArray()) {
            if (chara == 'L') {
                disp.remove(disp.first());
            } else if (chara == 'R') {
                disp.remove(disp.last());
            } else {
                disp.add(chara - '0');
            }
        }
        for (int i = 0; i < 10; i++) {
            if (disp.contains(i)) {
                System.out.print(0);
            } else {
                System.out.print(1);
            }
        }
        System.out.println();
    }
}