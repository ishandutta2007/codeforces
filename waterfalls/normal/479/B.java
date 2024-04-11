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
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    ArrayList<int[]> towers = new ArrayList<int[]>();
    st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) towers.add(new int[]{Integer.parseInt(st.nextToken()),i});
    
    // keep sorting and moving
    int[][] moves = new int[k][2];
    int[] instab = new int[k+1];
    for (int i=0;i<k;i++) {
      Collections.sort(towers,new Comparator<int[]>() {
        public int compare(int[] a, int[] b) {
          return (new Integer(a[0])).compareTo(b[0]);
        }
      });
      instab[i] = towers.get(towers.size()-1)[0]-towers.get(0)[0];
      int[] move = new int[]{towers.get(towers.size()-1)[1]+1,towers.get(0)[1]+1};
      towers.get(towers.size()-1)[0]-=1;
      towers.get(0)[0]+=1;
      moves[i] = move;
    }
    Collections.sort(towers,new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        return (new Integer(a[0])).compareTo(b[0]);
      }
    });
    instab[k] = towers.get(towers.size()-1)[0]-towers.get(0)[0];
    int min = 1000000;
    for (int i: instab) min = Math.min(min,i);
    int m = -1;
    for (int i=0;i<=k;i++) {
      if (instab[i]==min) {
        m = i;
        break;
      }
    }
    
    // print
    out.println(min+" "+m);
    for (int i=0;i<m;i++) out.println(moves[i][0]+" "+moves[i][1]);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}