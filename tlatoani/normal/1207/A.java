import java.util.Scanner;

public class ThereAreTwoTypesOfBurgers {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int t = in.nextInt(); t > 0; t--) {
            int b = in.nextInt();
            int p = in.nextInt();
            int f = in.nextInt();
            int h = in.nextInt();
            int c = in.nextInt();
            int profit = 0;
            if (h > c) {
                int beef = Math.min(p, b / 2);
                b -= 2 * beef;
                profit += h * beef;
                profit += c * Math.min(f, b / 2);
            } else {
                int chicken = Math.min(f, b / 2);
                b -= 2 * chicken;
                profit += c * chicken;
                profit += h * Math.min(p, b / 2);
            }
            System.out.println(profit);
        }
    }
}