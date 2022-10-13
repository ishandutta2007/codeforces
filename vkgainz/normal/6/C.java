import java.util.*;
public class susbus{
public static void main(String[] args){
   
   Scanner sc = new Scanner(System.in);
   int n = sc.nextInt();
   int [] bars = new int[n];
   int sum=0;
   for(int i=0;i<n;i++) {
      bars[i] = sc.nextInt();
      sum+=bars[i];
   }
   //  System.out.println(sum);
   int posIndex=0;
   int posSum=bars[0];
   while(posSum<sum-posSum){
      posIndex++;
      posSum+=bars[posIndex];
   }
   //  System.out.println(posIndex);
   int a = 0;
   for(int i=0;i<posIndex;i++){
      a+=bars[i];
   }
   //  System.out.println(a);
   if(a>sum-a-bars[posIndex]) {
      System.out.println(posIndex);
      System.out.println(n-posIndex);
   }
   else {
      System.out.println(posIndex+1);
      System.out.println(n-(posIndex+1));
   }
}
}