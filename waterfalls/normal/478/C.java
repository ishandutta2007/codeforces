import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int[] nums = new int[3];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<3;i++) nums[i] = Integer.parseInt(st.nextToken());
    Arrays.sort(nums);
    
    // write to out
    out.println(Math.min(((long) nums[0]+nums[1]+nums[2])/3,(long) nums[0]+nums[1]));
    
    // cleanup
    out.close();
    System.exit(0);
  }
}