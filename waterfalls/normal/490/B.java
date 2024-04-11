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
    HashMap<Integer,Integer> after = new HashMap<Integer,Integer>();
    HashMap<Integer,Integer> before = new HashMap<Integer,Integer>();
    HashSet<Integer> keys = new HashSet<Integer>();
    for (int i=0;i<n;i++) {
      StringTokenizer st = new StringTokenizer(f.readLine());
      int from = Integer.parseInt(st.nextToken());
      int to = Integer.parseInt(st.nextToken());
      after.put(from,to);
      before.put(to,from);
      keys.add(from);
      keys.add(to);
    }
    
    // find first even and first odd
    int firstEven = 0;
    int firstOdd = 0;
    for (int i: keys) {
      if (!after.containsKey(i)) firstOdd = i;
      if (!before.containsKey(i)) firstEven = i;
    }
    
    // find evens and odds
    ArrayList<Integer> even = new ArrayList<Integer>();
    ArrayList<Integer> odd = new ArrayList<Integer>();
    int prev = firstEven;
    even.add(prev);
    for (int i=0;i<(n+1)/2-1;i++) {
      prev = after.get(prev);
      even.add(prev);
    }
    prev = firstOdd;
    if (n%2==1) prev = before.get(0);
    odd.add(prev);
    for (int i=0;i<n/2-1;i++) {
      prev = before.get(prev);
      odd.add(prev);
    }
    Collections.reverse(odd);
    
    // print
    for (int i=0;i<n;i++) {
      if (i%2==0) out.print(even.get(i/2)+" ");
      else out.print(odd.get(i/2)+" ");
    }
    out.println();
    
    // cleanup
    out.close();
    System.exit(0);
  }
}