import java.util.Scanner;

public class GridGame {

    public static void main(String[] args) {
        boolean horizontal = false;
        boolean vertical = false;
        for (char chara : new Scanner(System.in).nextLine().toCharArray()) {
            if (chara == '0') {
                if (vertical) {
                    System.out.println("1 4");
                } else {
                    System.out.println("3 4");
                }
                vertical = !vertical;
            } else {
                if (horizontal) {
                    System.out.println("1 3");
                } else {
                    System.out.println("1 1");
                }
                horizontal = !horizontal;
            }
        }
    }
}