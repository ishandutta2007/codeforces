import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A371 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long l1 = Long.parseLong(st.nextToken());
        long r1 = Long.parseLong(st.nextToken());
        long l2 = Long.parseLong(st.nextToken());
        long r2 = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long ans = 0;
        if (r1 < l2) ans = 0;
        else if (r2 < l1) ans = 0;
        else if (l1 >= l2) {
            ans = Math.min(r1, r2) - l1 + 1;
            if (k >= l1 && k <= Math.min(r1, r2)) ans--;
        }
        else if (l2 >= l1) {
            ans = Math.min(r1, r2) - l2 + 1;
            if (k >= l2 && k <= Math.min(r1, r2)) ans--;
        }
        System.out.println(ans);
    }
}