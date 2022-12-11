// Working program using BufferedReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class D
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(
                              new InputStreamReader(System.in));
 
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        int stk[] = new int[200005];
        stk[0] = 1000;
        int sp = 0;
        int noover = 0;
        int ans = 0;
        int speed = 0;

        for (int i = 0; i < n; i++)
        {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            if (t == 1)
            {
                int x = Integer.parseInt(st.nextToken());
                while (x > stk[sp])
                {
                    ++ans;
                    --sp;
                }
                speed = x;
            }
            if (t == 2)
            {
                ans += noover;
                noover = 0;
            }
            if (t == 3)
            {
                int x = Integer.parseInt(st.nextToken());
                if (speed > x)
                {
                    ++ans;
                    continue;
                }
                stk[++sp] = x;
            }
            if (t == 4)
            {
                noover = 0;
            }
            if (t == 5)
            {
                sp = 0;
            }
            if (t == 6)
            {
                ++noover;
            }
        }

        System.out.println(ans);
    }
}