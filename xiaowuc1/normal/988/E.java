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
        while(true) {
            int ret = Integer.MAX_VALUE;
            String s = nextToken();
            ret = solve(s);
            for(int i = 1; i < s.length()-1 && s.charAt(i) == '0'; i++) {
                char[] x = s.toCharArray();
                char cache = x[i+1];
                for(int j = 1; j <= i; j++) {
                    x[j+1] = x[j];
                }
                x[1] = cache;
                ret = Math.min(ret, i + solve(new String(x)));
            }
            if(ret >= 1 << 25) {
                ret = -1;
            }
            pw.println(ret);
        }
        // exitImmediately();
    }

    public static int solve(String s) {
        int ret = 1 << 25;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != '0' && s.charAt(i) != '5') {
                continue;
            }
            ret = Math.min(ret, phase1(s, i));
        }
        return ret;
    }

    public static int phase1(String s, int chosenIndex) {
        int numSwapsPhase1 = s.length()-1-chosenIndex;
        char[] ret = s.toCharArray();
        char rightmost = s.charAt(chosenIndex);
        // ABCDEF
        // ABDEFC
        for(int i = chosenIndex; i + 1 < ret.length; i++) {
            ret[i] = ret[i+1];
        }
        ret[ret.length-1] = rightmost;
        if(ret[0] == '0') return Integer.MAX_VALUE;
        // moved the rightmost digit
        String phase2Init = new String(ret);
        int numSwapsPhase2 = 1 << 25;
        for(int i = 0; i < phase2Init.length()-1; i++) {
            int val = (phase2Init.charAt(i) - '0') * 10 + (phase2Init.charAt(phase2Init.length()-1) - '0');
            if(val % 25 != 0) {
                continue;
            }
            numSwapsPhase2 = Math.min(numSwapsPhase2, phase2(phase2Init, i));
        }
        return numSwapsPhase1 + numSwapsPhase2;
    }

    public static int phase2(String s, int chosenIndex) {
        int numSwaps = s.length()-2-chosenIndex;
        char[] ret = s.toCharArray();
        for(int i = chosenIndex; i + 1 < ret.length - 1; i++) {
            ret[i] = ret[i+1];
        }
        if(ret[0] == '0') return Integer.MAX_VALUE;
        return numSwaps;
    }

    /*
    ABCDEFGHIJKLMNOPQRSTUVWXYZ

    pick your rightmost digit O(18)
      force it to the end (maintaining leading zero constraint) O(18)
      pick your secondrightmost digit O(18)
        force it to the penultimate position (maintaining leading zero constraint) O(18)
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