import java.util.*;

public class susbus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  String s = sc.next();
  int count=0;
  for (int i=0;i<n;i++){
   if (s.charAt(i) == '8'){
    count++;
   }
  }
  int floor = (int) Math.floor(n/11);
  int asdf = Math.min(count,floor);
  System.out.println(asdf);
 }
}