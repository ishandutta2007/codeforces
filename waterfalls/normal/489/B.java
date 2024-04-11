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
    int[] boys = new int[n];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) boys[i] = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(f.readLine());
    int[] girls = new int[m];
    st = new StringTokenizer(f.readLine());
    for (int i=0;i<m;i++) girls[i] = Integer.parseInt(st.nextToken());
    Arrays.sort(boys);
    Arrays.sort(girls);
    
    // find matches
    boolean[] matched = new boolean[m];
    int count = 0;
    outer:
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (!matched[j] && Math.abs(girls[j]-boys[i])<2) {
          matched[j] = true;
          count+=1;
          continue outer;
        }
      }
    }
    
    // write to out
    out.println(count);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}