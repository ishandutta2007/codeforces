import java.util.*;

public class football{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    boolean b = false;
    for(int i = 0; i < s.length()-6; i++){
      if(s.substring(i,i+7).equals("1111111") || s.substring(i,i+7).equals("0000000")){
        b = true;
      }
    }
    if(b){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}