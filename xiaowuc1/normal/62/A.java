import java.io.*;
import java.util.*;
public class A62 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int aL = Integer.parseInt(st.nextToken());
        int aR = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int bL = Integer.parseInt(st.nextToken());
        int bR = Integer.parseInt(st.nextToken());
        if(valid(aL, bR) || valid(aR, bL))  {
            System.out.println("YES");
        }
        else    {
            System.out.println("NO");
        }
    }
    public static boolean valid(int girl, int guy)  {
        return guy >= girl - 1 && guy <= 2 * girl + 2;
    }
}