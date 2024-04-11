import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {

    private void solve() throws IOException {
        int n, a, i, sum=0, tmp;
        int v[]=new int[10];
        n=nextInt();
        for(i=0; i<n; i++){
            a=nextInt();
            v[a]++;
            sum+=a;
        }
        if (v[0]==0){
            print("-1");
            return;
        }
        if (sum%3!=0){
            for(i=sum%3; i<10; i+=3){
                if (v[i]>0){
                    sum-=i;
                    break;
                }
            }
            if (i>=10){
                tmp=2;
                for(i=3-sum%3; i<10; i+=3){
                    if (v[i]>0 && tmp>0){
                        tmp--;
                        sum-=i;
                        v[i]--;
                        i-=3;
                    }
                }
            }
            else{
                v[i]--;
            }
        }
        if (sum==0){
            printf("0");
            return;
        }
        for(i=9; i>=0; ){
            if (v[i]>0){
                print(i);
                v[i]--;
            }
            else{
                i--;
            }
        }
            
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