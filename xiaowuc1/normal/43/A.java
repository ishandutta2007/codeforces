import java.io.*;
public class A43 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s1 = null;
        String s2 = null;
        int g1 = 0;
        int g2 = 0;
        while(n-- > 0)  {
            String s = br.readLine();
            if(s1 == null || s1.equals(s))  {
                s1 = s;
                g1++;
            }
            else    {
                s2 = s;
                g2++;
            }
        }
        System.out.println(g1 > g2 ? s1 : s2);
    }
}