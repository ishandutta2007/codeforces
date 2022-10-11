import java.io.*;
import java.util.*;
public class A55 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] can = new boolean[n];
        int curr = 0;
        for(int i = 1; i <= n*n; i++)       {
            curr += i;
            curr %= n;
            can[curr] = true;
        }
        boolean win = true;
        for(boolean b: can)     {
            if(!b)
                win = false;
        }
        System.out.println(win ? "YES" : "NO");
    }
}