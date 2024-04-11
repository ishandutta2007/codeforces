import java.util.Scanner;
import java.lang.Math.*;

public class example
{
    static String[] str;
    static String target;
    static boolean[] visit;
    static int[] dp;
    static int len;
    static int n;
    
    static int D(int t)
    {
        if (t >= len) return 0;
        if (visit[t] == false)
        {
            visit[t] = true;
            dp[t] = 1234567890;
            
            for (int i = 0; i < n; i++)
            {
                int ptr = t;
                for (int j = 0; j < str[i].length(); j++)
                {
                    if (ptr < len && str[i].charAt(j) == target.charAt(ptr))
                    {
                        ++ptr;
                    }
                }
                
                if (ptr > t)
                {
                    dp[t] = Math.min(dp[t], D(ptr) + 1);
                }
            }
        }
        
        return dp[t];
    }
    
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        str = new String[n];
        
        for (int i = 0; i < n; i++) str[i] = in.next();
        
        target = in.next();
        len = target.length();
        
        dp = new int[len];
        visit = new boolean[len];
        
        int result = D(0);
        if (result > len) result = -1;
        System.out.println(result);
    }
}