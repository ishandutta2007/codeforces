import java.io.*;
import java.util.*;
public class A37 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        while(n-- > 0)  {
            int curr = Integer.parseInt(st.nextToken());
            if(!map.containsKey(curr))
                map.put(curr, 0);
            map.put(curr, 1+map.get(curr));
        }
        int max = 0;
        for(int x: map.keySet())    {
            max = Math.max(max, map.get(x));
        }
        System.out.println(max + " " + map.keySet().size());
    }
}