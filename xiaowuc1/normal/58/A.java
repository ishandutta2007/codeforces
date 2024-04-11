import java.io.*;
public class A58 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = "hello";
        int c = 0;
        for(int i = 0; i < s.length() && c < t.length(); i++)   {
            if(s.charAt(i) == t.charAt(c))
                c++;
        }
        System.out.println(c == t.length() ? "YES" : "NO");
    }
}