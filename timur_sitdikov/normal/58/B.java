import java.util.*;
import java.io.*;

public class A {
    Scanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int n, i;
        n = in.nextInt();
        i=2;
        while(n>1){
            for(; i<=n; i++){
                if (n%i==0)
                {
                    out.print(n + " ");
                    n/=i;
                    break;
                }
            }
        }
        out.print("1");
    }

    public void run() {
        try {
            /*in = new Scanner(new File("input.in"));
            out = new PrintWriter(new File("output.out"));*/
            in = new Scanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        
        

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
    }

    public static void main(String[] arg) {
        new A().run();
    }
}