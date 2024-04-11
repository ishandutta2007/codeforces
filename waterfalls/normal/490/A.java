import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int n = Integer.parseInt(f.readLine());
    LinkedList<Integer> first = new LinkedList<Integer>();
    LinkedList<Integer> second = new LinkedList<Integer>();
    LinkedList<Integer> third = new LinkedList<Integer>();
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=1;i<=n;i++) {
      int next = Integer.parseInt(st.nextToken());
      if (next==1) first.add(i);
      else if (next==2) second.add(i);
      else third.add(i);
    }
    
    // write to out
    out.println(Math.min(Math.min(first.size(),second.size()),third.size()));
    while (first.size()>0 && second.size()>0 && third.size()>0) {
      out.println(first.removeFirst()+" "+second.removeFirst()+" "+third.removeFirst());
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}