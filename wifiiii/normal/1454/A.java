import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(rd.readLine());
        while(t > 0) {
            int n = Integer.parseInt(rd.readLine());
            int[] a = new int[n];
            for(int i = 0; i < n; ++i) a[i] = (i + 1) % n + 1;
            for(int i = 0; i < n; ++i) {
                System.out.print(a[i] + " ");
            }
            System.out.println();
            t--;
        }
    }
}