import java.util.Arrays;
import java.util.Scanner;

public class Pillars {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Integer[] disks = new Integer[n];
        int maxix = 0;
        for (int i = 0; i < n; i++) {
            disks[i] = in.nextInt();
            if (disks[i] > disks[maxix]) {
                maxix = i;
            }
        }
        for (int i = 1; i < maxix; i++) {
            if (disks[i] <= disks[i - 1]) {
                System.out.println("nO");
                return;
            }
        }
        for (int i = maxix + 2; i < n; i++) {
            if (disks[i] >= disks[i - 1]) {
                System.out.println("nO");
                return;
            }
        }
        Arrays.sort(disks);
        for (int i = 1; i < n; i++) {
            if (disks[i].equals(disks[i - 1])) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("yEs");
    }
}