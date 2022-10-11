import java.io.*;
import java.util.*;
public class A38 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n-1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n-1; i++)
            list[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        a--;
        b--;
        int ret = 0;
        for(int i = a; i < b; i++)
            ret += list[i];
        System.out.println(ret);
    }
}