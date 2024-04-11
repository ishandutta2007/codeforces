import java.util.Scanner;

public class WOWFactor {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        long total = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'v' && s.charAt(i - 1) == 'v') {
                total++;
            }
        }
        long curr = 0;
        long answer = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == 'v' && s.charAt(i - 1) == 'v') {
                curr++;
            } else if (s.charAt(i) == 'o') {
                answer += curr * (total - curr);
            }
        }
        System.out.println(answer);
    }
}