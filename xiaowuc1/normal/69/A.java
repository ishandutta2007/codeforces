import java.io.*;
import java.util.*;
public class A69 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[3];
        for(int i = 0; i < n; i++)  {
            StringTokenizer st = new StringTokenizer(br.readLine());
            list[0] += Integer.parseInt(st.nextToken());
            list[1] += Integer.parseInt(st.nextToken());
            list[2] += Integer.parseInt(st.nextToken());
        }
        boolean flag = list[0] == 0 && list[1] == 0 && list[2] == 0;
        System.out.println(flag ? "YES" : "NO");
    }
}