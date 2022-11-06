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
    
    int check(int r, int r1, int r2, double d){
        double eps=1e-7;
        if (r+r2<d+eps){
            return 1;
        }
        if (r+d<r1+eps){
            return 1;
        }
        if (d+r2<r+eps){
            return 1;
        }
        return 0;
    }
    
    private void solve() throws IOException {
        int x1, y1, r1, R1, x2, y2, r2, R2, tmp, ans=0;
        double d;
        x1=nextInt();
        y1=nextInt();
        r1=nextInt();
        R1=nextInt();
        x2=nextInt();
        y2=nextInt();
        r2=nextInt();
        R2=nextInt();
        d=Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        ans+=check(r1, r2, R2, d);
        ans+=check(R1, r2, R2, d);
        ans+=check(r2, r1, R1, d);
        ans+=check(R2, r1, R1, d);
        print(ans);
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