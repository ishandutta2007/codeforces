import java.io.*;
public class A59 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int u = 0;
        int l = 0;
        for(int i = 0; i < s.length(); i++)     {
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
                l++;
            else
                u++;
        }
        if(l >= u)
            System.out.println(s.toLowerCase());
        else
            System.out.println(s.toUpperCase());
    }
}