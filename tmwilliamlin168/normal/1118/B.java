import java.util.*;
public class Sample {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ar[] = new int[n + 1];
        long odd = 0, even = 0;
        for(int i = 1; i <= n; i++) {
            ar[i] = sc.nextInt();
            if(i % 2 == 0) {
                even += ar[i];
            } else {
                odd += ar[i];
            }
        }
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) {
                odd = odd - ar[i] + ar[i - 1];
            } else {
                even = even - ar[i] + ar[i - 1];
            }
            if(even == odd) {
                count++;
            }
        }
        System.out.println(count);
    }
}