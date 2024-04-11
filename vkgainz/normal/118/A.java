import java.util.*;

public class SHREYASPRO{
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    String strlow = str.toLowerCase();
    String a = "";
    for (int i=0;i<str.length();i++){
      if (strlow.charAt(i) != 'a' && strlow.charAt(i) != 'e' && strlow.charAt(i) != 'i' && strlow.charAt(i) != 'o' && strlow.charAt(i) != 'u' && strlow.charAt(i) != 'y'){
        a = a+"."+strlow.charAt(i);
      }
      else {
        a = a;
      }
    }
    System.out.println(a);
  }
}