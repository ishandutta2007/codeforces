import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      String s = sc.next();
      int a = numOccur("Danil",s)+numOccur("Olya",s)+numOccur("Slava",s)+numOccur("Ann",s)+numOccur("Nikita",s);
      if(a==1) System.out.println("YES");
      else System.out.println("NO");
      /* *
      *  "Danil", "Olya", "Slava", "Ann" and "Nikita".


      */
   }
   public static int numOccur(String occur, String s){
      int count=0;
      for(int i=0;i<=s.length()-occur.length();i++){
         if(s.substring(i,i+occur.length()).equals(occur)) count++;
      }
      return count;
   }
}