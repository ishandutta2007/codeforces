import java.io.*;
import java.util.*;
public class A32 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] list = new int[n];
        for(int i = 0; i < n; i++)
            list[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(list);
        int ret = 0;
        for(int i = 0; i < n; i++)      {
            for(int j = i+1; j < n; j++)        {
                if(list[j] - list[i] <= d)      {
                    ret += 2;
                }
                else    {
                    break;
                }
            }
        }
        System.out.println(ret);
    }
}