import java.io.*;
import java.util.*;
public class A29 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] x = new int[n];
        int[] d = new int[n];
        for(int i = 0; i < n; i++)      {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            d[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < n; i++)      {
            for(int j = i+1; j < n; j++)        {
                if(x[j] == x[i] + d[i] && x[i] == x[j] + d[j])      {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }
}