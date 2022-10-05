import java.util.Scanner;

public class StickersAndToys {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tt = in.nextInt();
        for (int c = 0; c < tt; c++) {
            int n = in.nextInt();
            int s = in.nextInt();
            int t = in.nextInt();
            System.out.println(Math.max(
                    Math.min(t + 1, n - s + 1),
                    Math.min(s + 1, n - t + 1)
            ));
        }
    }
}