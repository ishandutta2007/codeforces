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
    
    // check each regiment
    for (int i=0;i<n;i++) {
      int[][] pos = new int[4][2];
      int[][] home = new int[4][2];
      for (int j=0;j<4;j++) {
        StringTokenizer st = new StringTokenizer(f.readLine());
        pos[j] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
        home[j] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
      }
      
      // bash
      int min = 13;
      for (int a=0;a<4;a++) {
        for (int b=0;b<4;b++) {
          for (int c=0;c<4;c++) {
            for (int d=0;d<4;d++) {
              int[][] newPos = new int[4][2];
              for (int j=0;j<4;j++) for (int k=0;k<2;k++) newPos[j][k] = pos[j][k];
              for (int j=0;j<a;j++) 
                newPos[0] = new int[]{home[0][0]+home[0][1]-newPos[0][1],home[0][1]+newPos[0][0]-home[0][0]};
              for (int j=0;j<b;j++) 
                newPos[1] = new int[]{home[1][0]+home[1][1]-newPos[1][1],home[1][1]+newPos[1][0]-home[1][0]};
              for (int j=0;j<c;j++) 
                newPos[2] = new int[]{home[2][0]+home[2][1]-newPos[2][1],home[2][1]+newPos[2][0]-home[2][0]};
              for (int j=0;j<d;j++) 
                newPos[3] = new int[]{home[3][0]+home[3][1]-newPos[3][1],home[3][1]+newPos[3][0]-home[3][0]};
              long[] dists = new long[6];
              int count = 0;
              for (int j=0;j<4;j++) for (int k=j+1;k<4;k++) {
                dists[count] = ((long) newPos[k][0]-newPos[j][0])*(newPos[k][0]-newPos[j][0])+
                               ((long) newPos[k][1]-newPos[j][1])*(newPos[k][1]-newPos[j][1]);
                count+=1;
              }
              Arrays.sort(dists);
              if (dists[0]==dists[1] && dists[1]==dists[2] && dists[2]==dists[3] && 
                  dists[4]==dists[5] && dists[0]!=0) {
                min = Math.min(min,a+b+c+d);
              }
            }
          }
        }
      }

      // print
      if (min<13) out.println(min);
      else out.println(-1);
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}