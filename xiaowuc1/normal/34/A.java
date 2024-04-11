import java.io.*;
import java.util.*;
public class A34 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)
            list[i] = Integer.parseInt(st.nextToken());
        int best = Math.abs(list[0] - list[n-1]);
        int a = 1;
        int b = n;
        for(int i = 1; i < n; i++)      {
            int diff = Math.abs(list[i] - list[i-1]);
            if(diff < best)     {
                best = diff;
                a = i;
                b = i+1;
            }
        }
        System.out.println(a + " " + b);
    }
}