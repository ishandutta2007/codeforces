import java.util.*;
import java.io.*;

public class A {
    Scanner in;
    PrintWriter out;

    public void solve() throws IOException {
        String s, h;
        int i, j;
        s=in.next();
        h="hello";
        char s1[]=s.toCharArray();
        char h1[]=h.toCharArray();
        for(i=0, j=0; i<s.length() && j<h.length(); i++){
            if (s1[i]==h1[j]){
                j++;
            }
        }
        if (j==5){
            out.write("YES");
        }
        else{
            out.write("NO");
        }
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