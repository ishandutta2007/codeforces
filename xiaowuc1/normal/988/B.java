import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;
/*
      br = new BufferedReader(new FileReader("input.txt"));
      pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
      br = new BufferedReader(new InputStreamReader(System.in));
      pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
    private static BufferedReader br;
    private static StringTokenizer st;
    private static PrintWriter pw;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = readInt();
        String[] l = new String[n];
        for(int i = 0; i < n; i++) {
            l[i] = nextToken();
        }
        Arrays.sort(l, new LengthComp());
        boolean good = true;
        for(int i = 0; good && i < l.length; i++) {
            for(int j = 0; good && j < i; j++) {
                good = l[i].contains(l[j]);
            }
        }
        if(!good) {
            pw.println("NO");
            exitImmediately();
        }
        pw.println("YES");
        for(String out: l) {
            pw.println(out);
        }
        exitImmediately();
    }

    static class LengthComp implements Comparator<String> {
        public int compare(String a, String b) {
            return a.length() - b.length();
        }
    }

    /*
    case 1: the strings are the same length
    A, B
    A is not a substring of B   EQUIVALENT    B is not a substring of A
    case 2: the strings are different lengths
    len(A) < len(B)
    */

    private static void exitImmediately() {
        pw.close();
        System.exit(0);
    }

    private static long readLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private static double readDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private static int readInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private static String nextLine() throws IOException  {
        if(!br.ready()) {
            exitImmediately();
        }
        st = null;
        return br.readLine();
    }

    private static String nextToken() throws IOException  {
        while(st == null || !st.hasMoreTokens())  {
            if(!br.ready()) {
                exitImmediately();
            }
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }
}