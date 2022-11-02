import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,k
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    LinkedList<Integer> goTo = new LinkedList<Integer>();
    st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) goTo.add(Integer.parseInt(st.nextToken()));
    Collections.sort(goTo);
    Collections.reverse(goTo);
    
    // bash
    int time = 0;
    while (goTo.size()>0) {
      time+=2*(goTo.get(0)-1);
      for (int i=0;i<k;i++) {
        goTo.removeFirst();
        if (goTo.size()==0) break;
      }
    }
    
    // write to out
    out.println(time);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}