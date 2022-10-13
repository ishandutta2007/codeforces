import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      String a = sc.next();
      String b = sc.next();
      int numS=0;
      int numF=0;
      for(int i=0;i<a.length();i++){
         if(a.charAt(i)=='7' && b.charAt(i) == '4') numS++;
         if(a.charAt(i) == '4' && b.charAt(i)=='7') numF++;
      }
      System.out.println(Math.max(numS,numF));
   }
}