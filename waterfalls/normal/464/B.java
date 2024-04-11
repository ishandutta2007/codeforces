import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader fi = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in coordinates
    int[][] coors = new int[8][3];
    for (int i=0;i<8;i++) {
      StringTokenizer st = new StringTokenizer(fi.readLine());
      coors[i] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
    }
    
    // bash arrangements
    int[][] arrs = new int[][]{new int[]{0,1,2},new int[]{0,2,1},new int[]{1,0,2},
                                     new int[]{1,2,0},new int[]{2,0,1},new int[]{2,1,0}};
    for (int[] b: arrs) for (int[] c: arrs) for (int[] d: arrs) for (int[] e: arrs)
    for (int[] f: arrs) for (int[] g: arrs) for (int[] h: arrs) {
      // find new coors
      int[][] newCoors = new int[8][3];
      newCoors[0] = coors[0];
      newCoors[1] = new int[]{coors[1][b[0]],coors[1][b[1]],coors[1][b[2]]};
      newCoors[2] = new int[]{coors[2][c[0]],coors[2][c[1]],coors[2][c[2]]};
      newCoors[3] = new int[]{coors[3][d[0]],coors[3][d[1]],coors[3][d[2]]};
      newCoors[4] = new int[]{coors[4][e[0]],coors[4][e[1]],coors[4][e[2]]};
      newCoors[5] = new int[]{coors[5][f[0]],coors[5][f[1]],coors[5][f[2]]};
      newCoors[6] = new int[]{coors[6][g[0]],coors[6][g[1]],coors[6][g[2]]};
      newCoors[7] = new int[]{coors[7][h[0]],coors[7][h[1]],coors[7][h[2]]};
      ArrayList<Double> dists = new ArrayList<Double>();
      for (int i=0;i<8;i++) for (int j=i+1;j<8;j++) {
        dists.add(Math.sqrt(((long) newCoors[i][0]-newCoors[j][0])*(newCoors[i][0]-newCoors[j][0])+
                            ((long) newCoors[i][1]-newCoors[j][1])*(newCoors[i][1]-newCoors[j][1])+
                            ((long) newCoors[i][2]-newCoors[j][2])*(newCoors[i][2]-newCoors[j][2])));
      }
      
      // if dists make cube
      if (isCube(dists)) {
        out.println("YES");
        for (int[] coor: newCoors) out.println(coor[0]+" "+coor[1]+" "+coor[2]);
        out.close();
        System.exit(0);
      }
    }
    
    // write to out
    out.println("NO");
    
    // cleanup
    out.close();
    System.exit(0);
  }
  
  // find if dists make cube
  static boolean isCube(ArrayList<Double> dists) {
    Collections.sort(dists);
    double err = 1e-9;
    double side = dists.get(0);
    if (side<err) return false;
    for (int i=0;i<12;i++) if (Math.abs(dists.get(i)-side)/side>err) return false;
    double fDia = side*Math.sqrt(2);
    for (int i=12;i<24;i++) if (Math.abs(dists.get(i)-fDia)/fDia>err) return false;
    double sDia = side*Math.sqrt(3);
    for (int i=24;i<28;i++) if (Math.abs(dists.get(i)-sDia)/sDia>err) return false;
    return true;
  }
}