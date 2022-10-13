import java.util.*;

public class ARUSHISSUPERPRO{
  public static void main(String[] args){
    Scanner ARUSH = new Scanner(System.in);
    String JATIN = ARUSH.next();
    String a = JATIN.substring(0,1).toUpperCase();
    for (int i=1;i<JATIN.length();i++){
      a = a+JATIN.charAt(i);
    }
    System.out.println(a);
  }
}