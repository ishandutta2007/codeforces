import java.util.*;
public class susbus{
   public static void main(String[] args){
	   Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int[] bayus = new int[n];
      for (int i=0;i<n;i++) bayus[i] = sc.nextInt();
      int max=0;
      int pos=0;
      for (int i=0;i<bayus.length;i++){
         if(bayus[i]>max){ 
            max=bayus[i];
         pos=i;
         }
      }
      System.out.println(pos+1);
      bayus[pos]=0;
      max=0;
      pos=0;
      for (int i=0;i<bayus.length;i++){
         if(bayus[i]>max) {
         max=bayus[i];
         pos=i;
         }
      }
      System.out.println(max);
   }
      
}