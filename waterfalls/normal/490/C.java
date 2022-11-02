import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    String key = f.readLine();
    StringTokenizer st = new StringTokenizer(f.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    
    // check all
    HashSet<Integer> works = new HashSet<Integer>();
    int left = 0;
    for (int i=0;i<key.length()-1;i++) {
      left*=10;
      left+=key.charAt(i)-48;
      left%=a;
      if (left==0) works.add(i);
    }
    int[] modB = new int[key.length()];
    modB[0] = 1;
    for (int i=1;i<key.length();i++) modB[i] = (10*modB[i-1])%b;
    int right = 0;
    for (int i=key.length()-1;i>0;i--) {
      right+=modB[key.length()-1-i]*(key.charAt(i)-48);
      right%=b;
      if (right==0 && key.charAt(i)-48!=0 && works.contains(i-1)) {
        out.println("YES");
        out.println(key.substring(0,i));
        out.println(key.substring(i));
        out.close();
        System.exit(0);
      }
    }

    // write to out
    out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}