import java.io.*;
import java.util.*;
public class A94 {
    public static void main(String[] args) throws IOException   { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        HashMap<String, String> map = new HashMap<String, String>();
        map.put(br.readLine(), "0");
        map.put(br.readLine(), "1");
        map.put(br.readLine(), "2");
        map.put(br.readLine(), "3");
        map.put(br.readLine(), "4");
        map.put(br.readLine(), "5");
        map.put(br.readLine(), "6");
        map.put(br.readLine(), "7");
        map.put(br.readLine(), "8");
        map.put(br.readLine(), "9");
        for(int i = 0; i < s.length(); i += 10)
            System.out.print(map.get(s.substring(i,i+10)));
    }
}