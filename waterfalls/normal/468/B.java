import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,a,b,ints
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(f.readLine());
    HashMap<Integer,Integer> in = new HashMap<Integer,Integer>();
    int[][] locs = new int[n][2];
    for (int i=0;i<n;i++) {
      int num = Integer.parseInt(st.nextToken());
      locs[i] = new int[]{num,i};
      in.put(num,i);
    }
    
    // use greedy
    boolean ok = true;
    int swap = 0;
    if (a>b) {swap = 1;
      int t = a;
      a = b;
      b = t;
    }
    Arrays.sort(locs,new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        return (new Integer(a[0])).compareTo(b[0]);
      }
    });
    int[] inB = new int[n];
    for (int[] i: locs) {
      if (in.containsKey(b-i[0])) {
        inB[i[1]] = 1-swap;
        in.remove(b-i[0]);
      } else if (in.containsKey(a-i[0])) {
        inB[i[1]] = swap;
        in.remove(a-i[0]);
      } else ok = false;
    }

    // write to out
    StringBuffer p = new StringBuffer();
    for (int i=0;i<n-1;i++) {
      p.append(inB[i]);
      p.append(" ");
    }
    p.append(inB[n-1]);
    if (ok) {
      out.println("YES");
      out.println(p.toString());
    } else {
      out.println("NO");
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}