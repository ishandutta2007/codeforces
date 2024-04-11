import java.util.*;
import java.io.*;
import java.math.*;

public class A {
    private void run(Scanner in, PrintWriter out) {
        int total = 0;
        String s = in.nextLine();
        int open = 0;
        int lastPos = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '#') {
                lastPos = i;
                total++;
                open--;
            } else if (s.charAt(i) == '(') {
                open++;
            } else open--;
            if (open < 0) {
                out.println(-1);
                return;
            }
        }
        int lastCloses = open+1;
        open = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '#') open -= lastPos == i ? lastCloses : 1; else
                if (s.charAt(i) == '(') open++; else open--;
            if (open < 0) {
                out.println(-1);
                return;
            }
        }
        for (int i = 0; i < total; i++) {
            out.println(i == total-1 ? lastCloses : 1);
        }
    }

    public void openAndRun(String[] args) throws Exception {
        Scanner in;
        if (args.length > 0 && args[0].equals("LOCAL")) {
            in = new Scanner(new File("input.txt"));
        } else {
            in = new Scanner(System.in);
        }
        PrintWriter out = new PrintWriter(System.out);
        run(in, out);
        out.close();
    }

    public static void main(String[] args) throws Exception {
        new A().openAndRun(args);
    }
}