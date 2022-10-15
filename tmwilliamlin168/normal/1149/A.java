import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []a = new int[3];

        for (int i = 0 ; i < n ; i ++) {
            a[sc.nextInt()] ++;
        }

        StringBuilder sb = new StringBuilder();

        if (a[1] != 0 && a[2] != 0) {
            sb.append("2 1 ");
            a[1] --;
            a[2] --;
        }

        while (a[2] != 0) {
            sb.append("2 ");
            a[2] --;
        }

        while (a[1] != 0) {
            sb.append("1 ");
            a[1] --;
        }

        System.out.println(sb);
    }
}