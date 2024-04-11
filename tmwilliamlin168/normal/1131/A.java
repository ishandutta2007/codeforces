import java.util.*;
public class sea
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int w1=s.nextInt();
        int h1=s.nextInt();
        int w2=s.nextInt();
        int h2=s.nextInt();
        int a=w1+2*h1+w2+2*h2+4+w1-w2;
        System.out.println(a);
    }
}