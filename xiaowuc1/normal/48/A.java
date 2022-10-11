import java.io.*;
public class A48 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String f = br.readLine();
        String m = br.readLine();
        String s = br.readLine();
        if(win(f,m) && win(f,s))    {
            System.out.println("F");
        }
        else if(win(m,f) && win(m,s))   {
            System.out.println("M");
        }
        else if(win(s,m) && win(s,f))   {
            System.out.println("S");
        }
        else    {
            System.out.println("?");
        }
        
    }
    public static boolean win(String a, String b)   {
        return (a.equals("rock") && b.equals("scissors")) || (a.equals("scissors") && b.equals("paper")) || (a.equals("paper") && b.equals("rock")); 
    }
}