import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x[] = new int[8];
        int y[] = new int[8];
        for(int i = 0; i < 8; ++i) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        TreeSet<Integer> setX = new TreeSet<>();
        TreeSet<Integer> setY = new TreeSet<>();
        for(int i = 0; i < 8; ++i) {
            setX.add(x[i]);
            setY.add(y[i]);
        }

        if (setX.size() != 3 || setY.size() != 3) {
            System.out.println("ugly");
            return;
        }

        Integer[] arrX = setX.toArray(new Integer[3]);
        Integer[] arrY = setY.toArray(new Integer[3]);

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                boolean found = false;
                for(int k = 0; k < 8; ++k) {
                    if (arrX[i] == x[k] && arrY[j] == y[k]) {
                        found = true;
                        break;
                    }
                }

                if (found == (i == 1 && j == 1)) {
                    System.out.println("ugly");
                    return;
                }
            }
        }

        System.out.println("respectable");
    }
}