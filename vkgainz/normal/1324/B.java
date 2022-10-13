import java.util.*;
public class susbus{
   public static void main(String [] args){
      Scanner sc = new Scanner(System.in);
      int t = sc.nextInt();
      for(int j=0;j<t;j++){
         int n = sc.nextInt();
         int [] vals = new int[n];
         int [] first= new int[n];
         int [] last = new int[n];
         Arrays.fill(first,-1); Arrays.fill(last,-1);
         for(int i=0;i<n;i++){
            vals[i] = sc.nextInt()-1;
         }
         for(int i=0;i<n;i++){
            if(first[vals[i]] == -1){
               first[vals[i]] = i;
            }
         }
         for(int i=n-1;i>=0;i--){
            if(last[vals[i]] == -1){
               last[vals[i]] = i;
            }
         }
         boolean x = false;
         for(int i=0;i<n;i++){
            if(last[i]-first[i]>=2){
              x = true;
              break;
            }
         }
         if(x){
            System.out.println("YES");
         }
         else{
            System.out.println("NO");
         }
      }
   }
}