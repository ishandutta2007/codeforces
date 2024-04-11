import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long [] values = new long[n/2];
      for(int i=0;i<n/2;i++) values[i] = sc.nextLong();
      long [] result = new long[n];
      long lindex = 0;
      long rindex = values[0];
      result[0] = lindex;
      result[n-1] = rindex;
      for(int i=1;i<n/2;i++){
         if(values[i]>values[i-1]){
            lindex+=values[i]-values[i-1];
         }
                     rindex = values[i]-lindex;

         result[i] = lindex;
         result[n-1-i] = rindex;
        
      }
      for(int i=0;i<n;i++) {
         System.out.print(result[i] + " ");
      }
   }
}