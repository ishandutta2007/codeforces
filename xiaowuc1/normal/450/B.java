import java.util.*;
public class Main {
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(System.in);
    long x = scan.nextLong();
    long y = scan.nextLong();
    int n = scan.nextInt() % 6;
    long ret = -1;
    final long MOD = 1000000007;
    if(n == 0) ret = x-y;
    if(n == 1) ret = x;
    if(n == 2) ret = y;
    if(n == 3) ret = y-x;
    if(n == 4) ret = -x;
    if(n == 5) ret = -y;
    ret += MOD;
    ret += MOD;
    ret %= MOD;
    System.out.println(ret);
  }
}