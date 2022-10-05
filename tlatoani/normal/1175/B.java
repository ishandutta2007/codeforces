import java.util.Scanner;
import java.util.Stack;

public class CatchOverflow {
    static final long MAX = (1L << 32) - 1;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        Stack<Long> stack = new Stack<>();
        long curr = 0;
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            if (line.startsWith("for")) {
                stack.push(curr);
                stack.push(Long.parseLong(line.substring(4)));
                curr = 0;
            } else if (line.equals("end")) {
                curr *= stack.pop();
                if (curr > MAX) {
                    overflow();
                    return;
                }
                curr += stack.pop();
                if (curr > MAX) {
                    overflow();
                    return;
                }
            } else {
                curr++;
                if (curr > MAX) {
                    overflow();
                    return;
                }
            }
        }
        System.out.println(curr);
    }

    static void overflow() {
        System.out.println("OVERFLOW!!!");
    }
}