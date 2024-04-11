import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int [] bayus= new int[5];
      for (int i=0;i<5;i++) bayus[i]=sc.nextInt();
      int sum=0;
      for (int i=0;i<5;i++) sum+=bayus[i];
      if(sum%5==0 && sum/5>0) System.out.println(sum/5);
      else System.out.println(-1);
   }
}