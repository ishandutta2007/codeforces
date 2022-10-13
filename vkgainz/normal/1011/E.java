import java.util.*;
public class E{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int k = sc.nextInt();
      int a[] = new int[n];
      for(int i=0;i<n;i++){
         a[i] = gcd(sc.nextInt()%k,k);
      }
      int gcd = a[0];
      for(int i=1;i<n;i++){
         gcd = gcd(gcd,a[i]);
      }
      gcd = gcd(gcd,k);
         ArrayList<Integer> arr = new ArrayList<Integer>();
         System.out.println(k/gcd);
         StringBuilder sb = new StringBuilder();
         for(int i=1;i<=k/gcd;i++){
            arr.add((gcd*i)%k);
         }
         Collections.sort(arr);
         for(int x : arr){
            sb.append(x);
            sb.append("\n");
         }
         System.out.println(sb.toString());
      
   }
   static int gcd(int a,int b){
      if(b==0) return a;
      
      return gcd(b,a%b);
   }
}