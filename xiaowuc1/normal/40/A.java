import java.io.*;
import java.util.*;
public class A40 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        double dist = Math.sqrt(x*x+y*y);
        if(dist == (int)dist)       {
            System.out.println("black");
            return;
        }
        if((x > 0 && y > 0) || (x < 0 && y < 0))    {
            System.out.println((int)dist%2 == 0 ? "black" : "white");
            return;
        }
        else    {
            System.out.println((int)dist%2 == 1 ? "black" : "white");
            return;
        }
    }
}