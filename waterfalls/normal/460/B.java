import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    StringTokenizer st = new StringTokenizer(f.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());
    
    // all possible sums
    int count = 0;
    ArrayList<Integer> answers = new ArrayList<Integer>();
    for (int s=1;s<=81;s++) {
      long res = 1;
      for (int i=0;i<a;i++) res*=s;
      res = res*b+c;
      if (res<0 || res>=1000000000) continue;
      int sum = 0;
      int ans = (int) res;
      while (res>0) {
        sum+=res%10;
        res/=10;
      }
      if (sum==s) {
        count+=1;
        answers.add(ans);
      }
    }

    // write to out
    out.println(count);
    Collections.sort(answers);
    for (int i: answers) out.print(i+" ");
    out.println();
    
    // cleanup
    out.close();
    System.exit(0);
  }
}