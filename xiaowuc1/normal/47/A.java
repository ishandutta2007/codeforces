import java.io.*;
import java.util.*;
public class A47 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Set<Integer> set = new HashSet<Integer>();
        for(int i = 1; i <= 500; i++)
            set.add((i*i+i)/2);
        System.out.println(set.contains(Integer.parseInt(br.readLine())) ? "YES" : "NO");
    }
}