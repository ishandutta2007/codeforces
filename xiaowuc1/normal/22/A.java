import java.io.*;
import java.util.*;
public class A22 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)
            list[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(list);
        for(int i = 1; i < n; i++)      {
            if(list[i] != list[0])  {
                System.out.println(list[i]);
                return;
            }
        }
        System.out.println("NO");
    }
}