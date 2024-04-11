import java.io.*;
import java.util.*;
public class A44 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Set<String> set = new HashSet<String>();
        int n = Integer.parseInt(br.readLine());
        while(n-- > 0)
            set.add(br.readLine());
        System.out.println(set.size());
    }
}