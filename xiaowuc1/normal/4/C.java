import java.io.*;
import java.util.*;
public class C  {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<String, Integer>();
        while(n-- > 0)  {
            String s = br.readLine();
            if(map.containsKey(s))  {
                int k = map.get(s);
                System.out.println(s + (k+1));
                map.put(s, k+1);
            }
            else    {
                System.out.println("OK");
                map.put(s, 0);
            }
        }
    }
}