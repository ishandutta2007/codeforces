import java.io.*;
import java.util.*;
public class A33 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int max = Integer.parseInt(st.nextToken());
        int[] list = new int[r];
        Arrays.fill(list, Integer.MAX_VALUE);
        while(n-- > 0)  {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            i--;
            list[i] = Math.min(list[i], c);
        }
        int ret = 0;
        for(int x: list)    {
            ret += x;
        }
        ret = Math.min(ret, max);
        System.out.println(ret);
    }
}