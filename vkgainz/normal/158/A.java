import java.util.*;

public class nextround {
  public static void main (String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int [] scores = new int[n];
    for (int i=0;i<n;i++){
      scores[i] = sc.nextInt();
    }
    int count=0;
    for (int i=0;i<n;i++){
      if (scores[i] >= scores[k-1]){
        count++;
      }
    }
    int numzero =0;
    for (int i=0;i<count;i++){
      if (scores[i] == 0){
        numzero++;
      }
    }
    
    System.out.println(count-numzero);
  }
  }