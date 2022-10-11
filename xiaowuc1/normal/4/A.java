import java.util.*;
public class A  {
    public static void main(String[] args)  {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        if(x==2)    {
            System.out.println("NO");
            return;
        }
        System.out.println(x%2 == 0 ? "YES" : "NO");
    }
}