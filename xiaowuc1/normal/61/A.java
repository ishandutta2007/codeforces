import java.io.*;
import java.util.*;
public class A61 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        for(int i = 0; i < s.length(); i++)
            System.out.print(s.charAt(i) ^ t.charAt(i));
    }
}