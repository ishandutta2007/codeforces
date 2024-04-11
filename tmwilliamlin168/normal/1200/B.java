import java.util.Scanner;
 
/**
 * https://codeforces.com/contest/1200/problem/B
 */
public class B1200 {
 
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int cases = scan.nextInt();
 
    for (int i = 0; i < cases; i++) {
      int n = scan.nextInt(); //  ,   
      int m = scan.nextInt(); //    
      int k = scan.nextInt(); //      
      int[] clms = new int[n];
      for (int j = 0; j < n; j++) {
        clms[j] = scan.nextInt();
      }
 
      for (int j = 0; j < clms.length; j++) {
        if (j == n - 1) {
          System.out.println("YES");
          break;
        }
 
        int goal = Math.max(clms[j + 1] - k, 0);
        m += clms[j] - goal;
        if (m < 0) {
          System.out.println("NO");
          break;
        }
      }
    }
    scan.close();
  }
}