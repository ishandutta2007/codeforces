import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in sticks
    int[] sticks = new int[6];
    StringTokenizer st = new StringTokenizer(f.readLine());
    for (int i=0;i<6;i++) sticks[i] = Integer.parseInt(st.nextToken());
    
    // find four of a stick
    Arrays.sort(sticks);
    int count = 1;
    int four = 0;
    for (int i=1;i<6;i++) {
      if (sticks[i]==sticks[i-1]) count+=1;
      else count = 1;
      if (count==4) four = sticks[i];
    }
    int a = sticks[0];
    int b = sticks[5];
    if (a==four) a = sticks[4];
    if (b==four) b = sticks[1];

    // write to out
    if (four==0) out.println("Alien");
    else if (a==b) out.println("Elephant");
    else out.println("Bear");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}