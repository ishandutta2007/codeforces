import java.io.*;
import java.util.*;
public class A54 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        boolean[] can = new boolean[n+1];
        int c = Integer.parseInt(st.nextToken());
        while(c-- > 0)
            can[Integer.parseInt(st.nextToken())] = true;
        int last = 0;
        int ret = 0;
        for(int i = 1; i <= n; i++)     {
            if(can[i] || i - last == k)     {
                ret++;
                last = i;
            }
        }
        System.out.println(ret);
    }
}