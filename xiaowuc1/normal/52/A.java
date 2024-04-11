import java.io.*;
import java.util.*;
public class A52 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] list = new int[4];
        StringTokenizer st = new StringTokenizer(br.readLine());
        while(n-- > 0)  {
            list[Integer.parseInt(st.nextToken())]++;
        }
        System.out.println(Math.min(list[1] + list[2], Math.min(list[1] + list[3], list[2] + list[3])));
    }
}