import java.util.*;

public class bussus{
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int n = sc.nextInt();
  long topPro = 1;
  for (int i=1;i<=2*n-2;i++){
   topPro*=i;
  }
  long botPro = 1;
  for (int i=1;i<=n-1;i++){
   botPro*=i;
  }
  long asdf = topPro/(botPro*botPro);
  System.out.println(asdf);
 }
}