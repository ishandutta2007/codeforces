import java.util.*;


public class Test
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();int b = sc.nextInt();int c = sc.nextInt();int d = sc.nextInt();
        if((a==d && ((a>0 && c>0) || c==0 ))){
            System.out.println(1);
        }else{
            System.out.println(0);
        }
    }
}