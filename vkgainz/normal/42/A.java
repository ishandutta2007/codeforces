import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc =new Scanner(System.in);
      int n= sc.nextInt();
      int V = sc.nextInt();
      int a[] = new int[n];
      for(int i=0;i<n;i++) a[i]=sc.nextInt();
      int b[] = new int[n];
      for(int i=0;i<n;i++) b[i] = sc.nextInt();
      
      double min=b[0]*1.0/a[0];
      for(int i=0;i<n;i++){
         min = Math.min(b[i]*1.0/a[i],min);
      }
      double sum=0;
      for(int i=0;i<n;i++) sum+=a[i];
      System.out.println(Math.min(sum*min,V));
   }
}