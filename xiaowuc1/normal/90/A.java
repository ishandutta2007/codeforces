import java.io.*;
import java.util.*;
public class A90 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = 27 + 3 * ((Integer.parseInt(st.nextToken())+1)/2);
        int b = 28 + 3 * ((Integer.parseInt(st.nextToken())+1)/2);
        int c = 29 + 3 * ((Integer.parseInt(st.nextToken())+1)/2);
        System.out.println(Math.max(a,Math.max(b,c)));
    }
}