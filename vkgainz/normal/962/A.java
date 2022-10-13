import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc=new Scanner(System.in);
      int n = sc.nextInt();
      int [] bayus = new int[n];
      long sum=0;
      for (int i=0;i<n;i++){ 
         bayus[i] = sc.nextInt();
         sum+=bayus[i];
   }
   int newsum=0;
   int pos=0;
   for (int i=0;i<n;i++){
      newsum+=bayus[i];
      if(newsum>=sum-newsum) {
         pos=i+1;
         break;
      }
   }
   System.out.println(pos);
   }
   
}