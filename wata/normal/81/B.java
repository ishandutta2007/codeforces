import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[] cs = sc.nextLine().toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < cs.length; i++) {
            if (cs[i] == ' ') {
            } else if (cs[i] == '.') {
                if (sb.length() > 0 && sb.charAt(sb.length() - 1) != ' ') sb.append(' ');
                sb.append("...");
                i += 2;
            } else if (cs[i] == ',') {
                sb.append(", ");
            } else {
                if (i > 0 && sb.length() > 0 && cs[i - 1] == ' ' && '0' <= sb.charAt(sb.length() - 1) && sb.charAt(sb.length() - 1) <= '9') {
                    sb.append(' ');
                }
                sb.append(cs[i]);
            }
        }
        String res = sb.toString();
        if (res.endsWith(" ")) res = res.substring(0, res.length() - 1);
        System.out.println(res);
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new B().run();
    }
}