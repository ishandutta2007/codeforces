import java.io.*;
public class A23 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        for(int length = s.length(); length > 0; length--)      {
            for(int start = 0; start + length <= s.length(); start++)       {
                String test = s.substring(start, start+length);
                if(s.indexOf(test) != s.lastIndexOf(test))  {
                    System.out.println(length);
                    return;
                }
            }
        }
        System.out.println(0);
    }
}