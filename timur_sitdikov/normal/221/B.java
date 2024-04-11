import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {

    private void solve() throws IOException {
        int x = nextInt(), tmp, ans=0;
        int v2[] = new int[10];
        int v1[] = new int[10];
        for(tmp=x; tmp!=0; tmp/=10){
            v1[tmp%10]=1;
        }   
        for(int i=1; i*i<=x; i++){
            if (x%i==0)
            {
                for(int j=0; j<10; j++){
                    v2[j]=0;
                }
                for(tmp=i; tmp!=0; tmp/=10){
                    v2[tmp%10]=1;
                }
                for(int j=0; j<10; j++){
                    if (v1[j]>0 && v2[j]>0){
                        ans++;
                        break;
                    }
                }
                if (x/i!=i){
                    for(int j=0; j<10; j++){
                        v2[j]=0;
                    }
                    for(tmp=x/i; tmp!=0; tmp/=10){
                        v2[tmp%10]=1;
                    }
                    for(int j=0; j<10; j++){
                        if (v1[j]>0 && v2[j]>0){
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        println(ans);
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