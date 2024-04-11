import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      int n= sc.nextInt();
      System.out.println(powerthree(n,1000003));
   }
   public static int powerthree(int n,int mod){
      //3^n-1
      if(n==1 || n==0) return 1;
      return 3*powerthree(n-1,mod)%mod;
      
   }
}