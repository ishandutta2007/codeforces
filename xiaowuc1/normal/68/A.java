import java.io.*;
import java.util.*;
public class A68 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int p1 = Integer.parseInt(st.nextToken());
        int p2 = Integer.parseInt(st.nextToken());
        int p3 = Integer.parseInt(st.nextToken());
        int p4 = Integer.parseInt(st.nextToken());
        int min = Integer.parseInt(st.nextToken());
        int max = Integer.parseInt(st.nextToken());
        int ret = 0;
        for(int i = min; i <= max; i++)     {
            int count = 0;
            if(i%p1%p2%p3%p4 == i)
                count++;
            if(i%p1%p2%p4%p3 == i)
                count++;
            if(i%p1%p3%p2%p4 == i)
                count++;
            if(i%p1%p3%p4%p2 == i)
                count++;
            if(i%p1%p4%p2%p3 == i)
                count++;
            if(i%p1%p4%p3%p2 == i)
                count++;
            if(i%p2%p1%p3%p4 == i)
                count++;
            if(i%p2%p1%p4%p3 == i)
                count++;
            if(i%p2%p3%p1%p4 == i)
                count++;
            if(i%p2%p3%p4%p1 == i)
                count++;
            if(i%p2%p4%p1%p3 == i)
                count++;
            if(i%p2%p4%p3%p1 == i)
                count++;
            if(i%p3%p1%p2%p4 == i)
                count++;
            if(i%p3%p1%p4%p2 == i)
                count++;
            if(i%p3%p2%p1%p4 == i)
                count++;
            if(i%p3%p2%p4%p1 == i)
                count++;
            if(i%p3%p4%p1%p2 == i)
                count++;
            if(i%p3%p4%p2%p1 == i)
                count++;
            if(i%p4%p1%p2%p3 == i)
                count++;
            if(i%p4%p1%p3%p2 == i)
                count++;
            if(i%p4%p2%p1%p3 == i)
                count++;
            if(i%p4%p2%p3%p1 == i)
                count++;
            if(i%p4%p3%p1%p2 == i)
                count++;
            if(i%p4%p3%p2%p1 == i)
                count++;
            if(count >= 7)
                ret++;
        }
        System.out.println(ret);
    }
}