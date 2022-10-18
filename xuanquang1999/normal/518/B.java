import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next(), t = sc.next();

        int cntS[] = new int[256];
        int cntT[] = new int[256];
        for(int i = 0; i < s.length(); ++i)
            cntS[s.charAt(i)]++;
        for(int i = 0; i < t.length(); ++i)
            cntT[t.charAt(i)]++;

        int yay = 0;
        for(char c = 0; c < 256; ++c) {
            if (Character.isAlphabetic(c)) {
                int x = Math.min(cntS[c], cntT[c]);
                yay += x;
                cntS[c] -= x;
                cntT[c] -= x;
            }
        }

        int whoops = 0;
        for(char c = 0; c < 256; ++c) {
            if (Character.isAlphabetic(c)) {
                char C = (Character.isLowerCase(c)) ? (char)(c-32) : (char)(c+32);
                int x = Math.min(cntS[c], cntT[C]);
                whoops += x;
                cntS[c] -= x;
                cntT[C] -= x;
            }
        }

        System.out.printf("%d %d\n", yay, whoops);
    }
}