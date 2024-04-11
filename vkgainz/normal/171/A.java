import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      System.out.println(a+reverseNum(b));
      
      
   }
   public static int reverseNum(int n){
      String s = String.valueOf(n);
      String result = "";
      for (int i=0;i<s.length();i++){
         result+=s.charAt(s.length()-i-1);
      }
      return Integer.parseInt(result);
   }
}