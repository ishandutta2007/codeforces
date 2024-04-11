import java.io.*;
import java.util.*;
public class B  {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int num = Integer.parseInt(st.nextToken());
        int[] min = new int[n];
        int[] max = new int[n];
        for(int i = 0; i < n; i++)  {
            st = new StringTokenizer(br.readLine());
            min[i] = Integer.parseInt(st.nextToken());
            max[i] = Integer.parseInt(st.nextToken());
        }
        int minP = 0;
        for(int x: min)
            minP += x;
        int maxP = 0;
        for(int x: max)
            maxP += x;
        if(num < minP || num > maxP)    {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
        int i = 0;
        for(int c = minP; c < num; c++) {
            if(min[i] < max[i]) {
                min[i]++;
            }
            else    {
                i++;
                c--;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int x: min) {
            sb.append(x + " ");
        }
        System.out.println(sb.toString().trim());
    }
}