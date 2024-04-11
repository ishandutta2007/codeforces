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
    int[] prev = new int[]{0,0,0,0,0,0,0,0};
    boolean ok = true;
    StringBuffer sb = new StringBuffer();
    for (int w=0;w<n;w++) {
      char[] nextC = f.readLine().toCharArray();
      int[] next = new int[8];
      for (int i=8-nextC.length;i<8;i++) next[i] = nextC[nextC.length+i-8]-48;
      boolean leading = true;
      outer:
      for (int i=0;i<9;i++) {
        if (i==8) {
          ok = false;
          break;
        }
        if (next[i]!=15 && next[i]!=0) leading = false;
        if (next[i]!=15 && next[i]>prev[i]) {
          for (int j=0;j<8;j++) if (next[j]==15) next[j] = 0;
          break;
        }
        if (next[i]!=15 && next[i]<prev[i]) ok = false;
        if (next[i]!=15 && next[i]==prev[i]) continue;
        if (next[i]==15 && prev[i]!=9) {
          boolean lesser = false;
          for (int j=i+1;j<8;j++) {
            if (next[j]<prev[j]) {
              next[i] = prev[i]+1;
              for (int k=0;k<8;k++) if (next[k]==15) next[k] = 0;
              break outer;
            } else if (next[j]>prev[j] && (next[j]!=15 || (next[j]==15 && prev[j]!=9)) && (leading && prev[i]==0)) {
              next[i] = 1;
              for (int k=0;k<8;k++) if (next[k]==15) next[k] = 0;
              break outer;
            } else if (next[j]>prev[j] && (next[j]!=15 || (next[j]==15 && prev[j]!=9))) {
              next[i] = prev[i];
              leading = false;
              continue outer;
            }
          }
          next[i] = prev[i]+1;
          for (int k=0;k<8;k++) if (next[k]==15) next[k] = 0;
          break outer;
        } else {
          next[i] = 9;
          leading = false;
        }
      }
      boolean need = true;
      for (int i=0;i<8;i++) {
        if (need && next[i]==0) continue;
        need = false;
        sb.append(next[i]);
      }
      sb.append("\n");
      prev = next;
    }
    
    // print
    if (ok) {
      out.println("YES");
      out.print(sb.toString());
    } else out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}