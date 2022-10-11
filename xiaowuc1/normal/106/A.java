import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        char win = s.charAt(0);
        StringTokenizer st = new StringTokenizer(br.readLine());
        String first = st.nextToken();
        String second = st.nextToken();
        if(first.charAt(1) != second.charAt(1))     {
            if(first.charAt(1) == win)
                System.out.println("YES");
            else
                System.out.println("NO");
            return;
        }
        String order = "6789TJQKA";
        int a = order.indexOf(first.charAt(0)+"");
        int b = order.indexOf(second.charAt(0)+"");
        if(a > b)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}