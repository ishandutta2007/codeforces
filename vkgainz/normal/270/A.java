import java.util.*;

public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int t = sc.nextInt();
      int [] bayus = new int[t];
      for (int i=0;i<t;i++) bayus[i] = sc.nextInt();
      for (int i=0;i<t;i++){
      if(360%(180-bayus[i])==0) System.out.println("YES");
      else System.out.println("NO");
      }
   }
}