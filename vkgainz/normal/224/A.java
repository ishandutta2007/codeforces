import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      long bibbas = a*b;
      // System.out.println(bibbas);
      int nibbas = (int) Math.sqrt(bibbas*c);
      // System.out.println(nibbas);
      int s1 = nibbas/a;
      int s2 = nibbas/b;
      int s3 = nibbas/c;
      System.out.println(4*(s1+s2+s3));
   }
}