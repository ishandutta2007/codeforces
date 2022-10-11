import java.io.*;
import java.util.*;
public class A9 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = Math.max(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        if(max == 1)
            System.out.println("1/1");
        if(max == 2)
            System.out.println("5/6");
        if(max == 3)
            System.out.println("2/3");
        if(max == 4)
            System.out.println("1/2");
        if(max == 5)
            System.out.println("1/3");
        if(max == 6)
            System.out.println("1/6");
    }
}