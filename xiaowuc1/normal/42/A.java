import java.io.*;
import java.util.*;
public class A42 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int total = Integer.parseInt(st.nextToken());
        int[] list = new int[n];
        double[] amt = new double[n];
        int[] max = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)  {
            list[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++)  {
            max[i] = Integer.parseInt(st.nextToken());
        }
        int sum = 0;
        for(int xx: list)   {
            sum += xx;
        }
        for(int i = 0; i < n; i++)  {
            amt[i] = 1.0 * list[i] / sum;
        }
        double minV = 0;
        double maxV = total;
        outer: for(int i = 0; i < 100; i++) {
            double mid = (minV+maxV)/2;
            for(int k = 0; k < n; k++)  {
                if(mid * amt[k] > max[k])   {
                    maxV = mid;
                    continue outer;
                }
            }
            minV = mid;
        }
        System.out.println(minV);
    }
}