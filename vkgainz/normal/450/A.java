import java.util.*;

public class susbus{
 public static void main(String[] args0){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  int m = sc.nextInt();
  int [] child = new int[n];
  for (int i=0;i<n;i++){
   child[i] = sc.nextInt();
  }
  int [] nibbas = new int[n];
  for (int i=0;i<n;i++){
   nibbas[i] = (child[i]-1)/m+1;
  }
  int max=0;
  int pos=0;
  for (int i=0;i<n;i++){
   if(nibbas[i]>=max){
    max=nibbas[i];
    pos=i;
   }
  }
  System.out.println(pos+1);
 }
}