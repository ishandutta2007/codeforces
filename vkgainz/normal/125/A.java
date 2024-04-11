import java.util.*;
public class susbus{
   
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int c = sc.nextInt();
      int in= 0;
      int feet = c/36;
      if(c%36==35){
         feet++;
      }
      int cm = c-36*feet;
      if(cm%3==0 || cm%3==1) in += cm/3;
      else in += cm/3+1;
   
     if(c%36==35) in--;
      System.out.println(feet + " "+in);
   }
}