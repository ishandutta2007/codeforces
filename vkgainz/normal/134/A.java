import java.util.*;
public class susbus {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] bayus = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            bayus[i] = sc.nextInt();
            sum += bayus[i];
        }
        if (sum%n != 0) {
            System.out.println(0);
            return;
        }
        int avg = sum/n;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (bayus[i] == avg) {
                count++;
            }
        }
        System.out.println(count);
        for (int i = 0; i < n; i++) {
            if (bayus[i] == avg) {
                System.out.print(i+1+" ");
            }
        }
    }
}