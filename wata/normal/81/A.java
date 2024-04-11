import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class A {
    Scanner sc = new Scanner(System.in);
    
    void run() {
        char[] cs = sc.nextLine().toCharArray();
        int s = 0;
        for (int i = 0; i < cs.length; i++) {
            if (i + 1 < cs.length && cs[i] == cs[i + 1]) {
                i++;
            } else {
                if (s > 0 && cs[s - 1] == cs[i]) {
                    s--;
                } else {
                    cs[s++] = cs[i];
                }
            }
        }
        System.out.println(new String(cs, 0, s));
    }
    
    void debug(Object...os) {
        System.err.println(deepToString(os));
    }
    
    public static void main(String[] args) {
        new A().run();
    }
}