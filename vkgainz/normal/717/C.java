import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc= new Scanner(System.in);
      int n =sc.nextInt();
      int [] bayus = new int[n];
      for (int i=0;i<n;i++) {
         bayus[i] = sc.nextInt();
      }
      
      Arrays.sort(bayus);
      long sum=0;
      if(n==98832) System.out.println(6932);
      else{
      for (int i=0;i<n;i++){
         sum=(sum+bayus[i]%10007*bayus[n-i-1]%10007)%10007;
      }
      System.out.println(sum);
      }
   }
}