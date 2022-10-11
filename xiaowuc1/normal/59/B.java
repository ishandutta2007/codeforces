import java.io.*;
import java.util.*;
public class B59 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)
            list[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(list);
        int sum = 0;
        for(int x: list)
            sum += x;
        if(sum%2==1)
            System.out.println(sum);
        else    {
            for(int xx: list)           {
                if(xx%2==1)     {
                    System.out.println(sum-xx);
                    return;
                }
            }
            System.out.println(0);
        }
    }
}