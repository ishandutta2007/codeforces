import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,w
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int w = Integer.parseInt(st.nextToken());
    
    // special case
    if (w==1) out.println(n);
    else {
      // read in differences
      int[] wall = new int[n-1];
      st = new StringTokenizer(f.readLine());
      int prev = Integer.parseInt(st.nextToken());
      for (int i=0;i<n-1;i++) {
        wall[i] = Integer.parseInt(st.nextToken())-prev;
        prev+=wall[i];
      }
      int[] ele = new int[w-1];
      st = new StringTokenizer(f.readLine());
      prev = Integer.parseInt(st.nextToken());
      for (int i=0;i<w-1;i++) {
        ele[i] = Integer.parseInt(st.nextToken())-prev;
        prev+=ele[i];
      }
      
      // special case
      if (w==2) {
        int total = 0;
        for (int i: wall) if (ele[0]==i) total+=1;
        out.println(total);
      } else {
        // KMP algo
        // build table
        int[] table = new int[w-1];
        table[0] = -1;
        table[1] = 0;
        for (int i=2;i<w-1;i++) {
          if (ele[i-1]==ele[table[i-1]]) table[i] = table[i-1]+1;
          else table[i] = 0;
        }
        
        // search
        int count = 0;
        int i = 0;
        int j = 0;
        while (i+j<n-1) {
          if (ele[j]==wall[i+j]) {
            if (j==w-2) {
              count+=1;
              i+=j-table[j];
              j = table[j];
            } else j+=1;
          } else {
            if (table[j]>-1) {
              i+=j-table[j];
              j = table[j];
            } else {
              i+=1;
              j = 0;
            }
          }
        }
        out.println(count);
      }
    }
    // cleanup
    out.close();
    System.exit(0);
  }
}