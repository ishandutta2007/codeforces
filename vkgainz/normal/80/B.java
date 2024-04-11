import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      String s = sc.next();
      int hour = Integer.parseInt(s.substring(0,2));
      int minute = Integer.parseInt(s.substring(3));
      double add = minute*1.0/2;
      if(hour>=12) hour = hour-12;
      
      System.out.println(hour*30+add);
      System.out.println(6*minute);
   }
}