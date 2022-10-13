import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int a = sc.nextInt();
      int m = sc.nextInt();
      int k = m/a;
      int y = a/m;
      
       if((a%m==0 && isPowerOfTwo(y)) || (m%a==0 && isPowerOfTwo(k)) || isPowerOfTwo(m)) System.out.println("Yes");
      
      else System.out.println("No");
      
   }
   public static boolean isPowerOfTwo(int n){
      if(n==0) return false;
         while(n>1){
            if(n%2!= 0) return false;
            
            n=n/2;
         }
         return true;
      }
   }


// if m/a is power of two then we're done