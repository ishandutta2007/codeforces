import java.util.*;
public class susbus{
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      long n= sc.nextLong();
      long k= sc.nextLong();
      long s=  sc.nextLong();
      //move at least 1, at most n-1 each move
      long j = (n-1)*k;
//      System.out.println(j);
//      System.out.println(j-s);
      if(k>s || j<s) {
         System.out.println("NO");
         return;
      }
      System.out.println("YES");
      int numMove=0;
      while(s-(numMove+1)*(n-1)>k-(numMove+1)) {
         numMove++;
      }
      s = s-(numMove)*(n-1);
      k = k-numMove;
//       System.out.println(numMove);
      for(int i=0;i<numMove;i++){
         if(i%2==0) {
            System.out.print(n + " ");
         }
         else {
            System.out.print(1 + " ");
         }
      }
//       System.out.println(s);
      long add = (int) s+1-k;
      s-=add;
//      System.out.println(s);
      long left = 0;
      if(numMove%2==1){
         System.out.print(n-add + " ");
         left=n-add;
      }
      else {
         System.out.print(1+add + " ");
         left=1+add;
      }
//      System.out.print("whatever is left is "  + left);
      int state = 0;
      while(s>0){
    	 if(left<n) {
         if(state%2==0) System.out.print(left+1 + " ");
         else System.out.print(left + " ");
         state++;
         s--;
    	 }
    	 else {
    		 if(state%2==0) System.out.print(left-1 + " ");
             else System.out.print(left + " ");
             state++;
             s--; 
    	 }
      }
   }
}