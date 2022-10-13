import java.util.*;
public class banhmi{
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      int n = sc.nextInt();
      int [] values = new int[n];
      for(int i=0;i<n;i++){
         values[i] = sc.nextInt();
      }
      boolean [] work = new boolean[n-1];
      for(int i=0;i<n-1;i++){
         if(values[i]*2>=values[i+1]){
            work[i] = true;
         }
      }
      int curr =0;
      int max =0;
      while(curr<work.length){
         int temp = curr;
         if(work[curr]==true){
            while(curr < work.length && work[curr]==true){
               curr++;
            }
            max = Math.max(max,curr-temp);

         }
         else{
            curr++;
         }
         
      }
      System.out.println(max+1);
}
}