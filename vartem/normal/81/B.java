import java.io.*;
import java.util.*;

public class Sequence {

    void solve() throws Exception {
        String s = in.readLine();
        int i = 0;
        boolean wasspace = false;
        int t = -1;
        boolean fl = false;
        while (i < s.length()) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                if (t == 0 && fl == true) {
                    out.print(' ');
                    fl = false;
                }
                out.print(c);
                wasspace = false;
                fl = false;
                t = 0;
            } else if (c == ',') {
                out.print(',');
                if (i != s.length() - 1) {
                    out.print(" ");
                    wasspace = true;
                }
                fl = false;
                t = 1;
            } else if (c == '.') {
                if (!wasspace && i != 0)
                    out.print(' ');
                out.print("...");
                fl = false;
                wasspace = false;
                i += 2;
                t = 2;
            } else if (c == ' ') {
                fl = true;
            }           
            i++;
        }
    }
    
    void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    BufferedReader in;
    StringTokenizer st;
    PrintWriter out;
    final String filename = new String("Sequence").toLowerCase();

    String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    public static void main(String[] args) {
        new Sequence().run();
    }

}