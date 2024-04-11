import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int t =sc.nextInt();
      long [] bayus = new long[t];
      for (int i=0;i<t;i++) bayus[i] = sc.nextLong();
      for (int i=0;i<t;i++){
         if(bayus[i]%4==0) System.out.println(4*bayus[i]+1);
         if(bayus[i]%4==1) System.out.println(bayus[i]*2+1);
         if(bayus[i]%4==2) System.out.println(4*bayus[i]+1);
         if(bayus[i]%4==3) System.out.println(bayus[i]+1);
      }
   }
}