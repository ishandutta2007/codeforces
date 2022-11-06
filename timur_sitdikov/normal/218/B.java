import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {

    private void solve() throws IOException {
        int m, n, i, j, mini, mn, ansmin, ansmax;
        n=nextInt();
        m=nextInt();
        int v[]=new int[m];
        int v1[]=new int[m];
        for(j=0; j<m; j++){
            v[j]=nextInt();
            v1[j]=v[j];
        }
        ansmin=0;
        ansmax=0;
        for(i=0; i<n; i++){
            mini=-1;
            mn=10000;
            for(j=0; j<m; j++){
                if (v[j]<mn && v[j]>0){
                    mini=j;
                    mn=v[j];
                }
            }
            ansmin+=mn;
            v[mini]--;
            mini=-1;
            mn=0;
            for(j=0; j<m; j++){
                if (v1[j]>mn){
                    mini=j;
                    mn=v1[j];
                }
            }
            ansmax+=mn;
            v1[mini]--;
        }
        print(ansmax + " " + ansmin);
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