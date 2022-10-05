import java.util.Scanner;

public class Knights {

    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        StringBuilder answer = new StringBuilder();
        char[] color = new char[]{'W', 'B'};
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                answer.append(color[(x + y) % 2]);
            }
            answer.append('\n');
        }
        System.out.println(answer);
    }
}