import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {

    int gcd(int a, int b){
        return (b!=0)? gcd(b, a%b): a;
    }
    private void solve() throws IOException {
        int a, a1, b, b1, n, m, i, g;
        n=nextInt();
        m=nextInt();
        a=nextInt();
        for(i=0; i<n; i++){
            a1=nextInt();
        }
        b=nextInt();
        for(i=0; i<m; i++){
            b1=nextInt();
        }
        if (m>n){
            print("0/1");
            return;
        }
        if (n>m){
            if (a*b<0){
                print("-");
            }
            print("Infinity");
            return;
        }
        g=gcd(a, b);
        a/=g;
        b/=g;
        if (b<0){
            a=-a;
            b=-b;
        }
        print(a + "/" + b);
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextToken());
    }

    private double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private void print(Object o) {
        writer.print(o);
    }

    private void println(Object o) {
        writer.println(o);
    }

    private void printf(String format, Object... o) {
        writer.printf(format, o);
    }

    public static void main(String[] args) {
        long time = System.currentTimeMillis();
        Locale.setDefault(Locale.US);
        new A().run();
        System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(13);
        }
    }
}