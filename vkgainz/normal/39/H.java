import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int k =sc.nextInt();
      int [][] result = new int[k-1][k-1];
      for (int i=0;i<k-1;i++){
         for (int j=0;j<k-1;j++){
          result[i][j]=(i+1)*(j+1);

         }
      }
      for (int i=0;i<k-1;i++){
         for (int j=0;j<k-1;j++){
            result[i][j] = convertBase(result[i][j],k);
         }
      }
      for (int i = 0; i < k-1; i++) {
    for (int j = 0; j < k-1; j++) {
        System.out.print(result[i][j] + " ");
    }
    System.out.println();
}
      
   }
   public static int convertBase(int n, int base){
      String nibbas = "";
      while(n>0){
         nibbas+=n%base;
         n=n/base;
      }
      String bibba = "";
      for (int i=0;i<nibbas.length();i++){
         bibba+=nibbas.charAt(nibbas.length()-i-1);
      }
      return Integer.parseInt(bibba);
   }
}