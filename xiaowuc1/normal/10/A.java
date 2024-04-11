import java.io.*;
import java.util.*;
public class A10 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int p1 = Integer.parseInt(st.nextToken());
        int p2 = Integer.parseInt(st.nextToken());
        int p3 = Integer.parseInt(st.nextToken());
        int t1 = Integer.parseInt(st.nextToken());
        int t2 = Integer.parseInt(st.nextToken());
        n--;
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int finish = Integer.parseInt(st.nextToken());
        long ret = 0;
        ret += (finish-start)*p1;
        while(n-- > 0)      {
            st = new StringTokenizer(br.readLine());
            int nextStart = Integer.parseInt(st.nextToken());
            int nextFinish = Integer.parseInt(st.nextToken());
            if(nextStart - finish <= t1)    {
                ret += p1*(nextStart-finish);
            }
            else {
                if(nextStart - finish >= t1)        {
                    ret += p1*t1;
                    finish += t1;
                }
                if(nextStart - finish <= t2)    {
                    ret += p2*(nextStart-finish);
                }
                else    {
                    if(nextStart - finish >= t2)        {
                        ret += p2*t2;
                        finish += t2;
                    }
                    if(nextStart - finish >= 0) {
                        ret += p3*(nextStart-finish);
                    }
                }
            }
            ret += p1 * (nextFinish-nextStart);
            start = nextStart;
            finish = nextFinish;
        }
        System.out.println(ret);
    }
}