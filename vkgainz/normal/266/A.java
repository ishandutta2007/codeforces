import java.util.*;

public class sjdoisdjoisd{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String s= sc.next();
    int count=0;
    for (int i=0;i<n-1;i++){
      if (s.substring(i,i+1).equals(s.substring(i+1,i+2))){
        count++;
      }
    }
     System.out.println(count);
  }
}